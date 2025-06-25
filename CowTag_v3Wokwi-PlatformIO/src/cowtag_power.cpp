#include <Arduino.h>
#include <WiFi.h>
#include <esp_sleep.h>
#include <esp_wifi.h>
#include <esp_bt.h>
#include "cowtag_power.h"
#include "cowtag_config.h"

CowTagPower::CowTagPower() {
    current_mode = POWER_ACTIVE;
    last_activity_time = 0;
    battery_level = 100.0;
    low_battery_warning = false;
}

void CowTagPower::begin() {
    // Configure ADC for battery reading
    analogReadResolution(12);
    analogSetAttenuation(ADC_11db);
    
    // Disable WiFi and Bluetooth to save power
    WiFi.mode(WIFI_OFF);
    btStop();
    
    // Update initial battery level
    updateBatteryLevel();
    
    Serial.println("Power management initialized");
}

void CowTagPower::setMode(PowerMode mode) {
    if (current_mode == mode) return;
    
    Serial.print("Power mode changing from ");
    Serial.print(current_mode);
    Serial.print(" to ");
    Serial.println(mode);
    
    current_mode = mode;
    
    switch (mode) {
        case POWER_ACTIVE:
            enablePeripherals();
            setCpuFrequencyMhz(240); // Full speed
            break;
            
        case POWER_LOW:
            setCpuFrequencyMhz(80);  // Reduced speed
            disablePeripherals();
            break;
            
        case POWER_DEEP_SLEEP:
            disablePeripherals();
            // Deep sleep will be handled separately
            break;
            
        case POWER_EMERGENCY:
            setCpuFrequencyMhz(80);
            disablePeripherals();
            // Keep only essential functions
            break;
    }
}

PowerMode CowTagPower::getMode() {
    return current_mode;
}

void CowTagPower::updateBatteryLevel() {
    // Read battery voltage (pin 35 on TTGO T-Beam)
    int raw = analogRead(35);
    float voltage = (raw / 4095.0) * 2 * 3.3 * 1.1; // Voltage divider compensation
    
    // Convert voltage to percentage (assuming Li-Ion battery)
    // 4.2V = 100%, 3.0V = 0%
    battery_level = ((voltage - 3.0) / 1.2) * 100.0;
    
    // Clamp to valid range
    if (battery_level > 100.0) battery_level = 100.0;
    if (battery_level < 0.0) battery_level = 0.0;
    
    // Check for low battery
    if (battery_level < EMERGENCY_BATTERY_LEVEL && !low_battery_warning) {
        low_battery_warning = true;
        Serial.println("LOW BATTERY WARNING!");
    }
    
    if (battery_level < 5.0) {
        setMode(POWER_EMERGENCY);
    } else if (battery_level < 20.0 && current_mode == POWER_ACTIVE) {
        setMode(POWER_LOW);
    }
}

float CowTagPower::getBatteryLevel() {
    return battery_level;
}

bool CowTagPower::isLowBattery() {
    return battery_level < EMERGENCY_BATTERY_LEVEL;
}

void CowTagPower::enterDeepSleep(uint64_t time_us) {
    Serial.print("Entering deep sleep for ");
    Serial.print(time_us / 1000000);
    Serial.println(" seconds");
    
    // Configure wake-up source
    esp_sleep_enable_timer_wakeup(time_us);
    
    // Optionally enable wake-up on external interrupt (e.g., for emergency)
    // esp_sleep_enable_ext0_wakeup(GPIO_NUM_33, 0);
    
    // Disable all peripherals
    disablePeripherals();
    
    // Enter deep sleep
    esp_deep_sleep_start();
}

void CowTagPower::disablePeripherals() {
    // Turn off LEDs
    digitalWrite(2, LOW);  // Status LED
    digitalWrite(4, LOW);  // Error LED
    
    // Reduce peripheral power
    // Note: Be careful not to disable peripherals that are actively needed
    
    Serial.println("Peripherals disabled for power saving");
}

void CowTagPower::enablePeripherals() {
    // Re-enable peripherals as needed
    pinMode(2, OUTPUT);  // Status LED
    pinMode(4, OUTPUT);  // Error LED
    
    Serial.println("Peripherals enabled");
}

void CowTagPower::updateActivity() {
    last_activity_time = millis();
}

bool CowTagPower::shouldSleep() {
    // Don't sleep in emergency mode
    if (current_mode == POWER_EMERGENCY) {
        return false;
    }
    
    // Sleep if no activity for extended period (configurable)
    uint32_t idle_time = millis() - last_activity_time;
    
    switch (current_mode) {
        case POWER_ACTIVE:
            return idle_time > 300000; // 5 minutes idle
            
        case POWER_LOW:
            return idle_time > 120000; // 2 minutes idle
            
        case POWER_DEEP_SLEEP:
            return true; // Always sleep in this mode
            
        default:
            return false;
    }
}