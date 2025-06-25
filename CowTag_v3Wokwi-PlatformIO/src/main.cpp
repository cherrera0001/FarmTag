#include <Arduino.h>
#include "cowtag_config.h"
#include "cowtag_sensors.h"
#include "cowtag_lora.h"
#include "cowtag_power.h"
#include "cowtag_data.h"

// Global instances
CowTagSensors sensors;
CowTagLoRa lora;
CowTagPower power;
CowTagData dataManager;

// Timing variables
unsigned long last_sensor_read = 0;
unsigned long last_lora_tx = 0;
unsigned long last_gps_update = 0;

void setup() {
    Serial.begin(115200);
    delay(1000); // Give time for serial to initialize
    Serial.println("CowTag V1 Starting...");
    
    // Initialize power management first
    power.begin();
    power.setMode(POWER_ACTIVE);
    Serial.println("Power management initialized");
    
    // Initialize sensors
    if (!sensors.begin()) {
        Serial.println("Error initializing sensors!");
        // Don't halt completely, continue with limited functionality
    } else {
        Serial.println("Sensors initialized successfully");
    }
    
    // Initialize LoRaWAN
    if (!lora.begin()) {
        Serial.println("Error initializing LoRa!");
        // Continue without LoRa for testing
    } else {
        Serial.println("LoRa initialized successfully");
    }
    
    // Initialize status LEDs and buzzer
    pinMode(2, OUTPUT);   // Status LED (green)
    pinMode(4, OUTPUT);   // Emergency LED (red)
    pinMode(18, OUTPUT);  // Movement LED (blue)
    pinMode(25, OUTPUT);  // Buzzer for alarms
    pinMode(33, INPUT_PULLUP); // Emergency button
    
    // Flash LEDs to indicate startup sequence
    Serial.println("Initializing CowTag systems...");
    for (int i = 0; i < 3; i++) {
        digitalWrite(2, HIGH);  // Status
        delay(200);
        digitalWrite(18, HIGH); // Movement
        delay(200);
        digitalWrite(4, HIGH);  // Emergency
        delay(200);
        digitalWrite(2, LOW);
        digitalWrite(18, LOW);
        digitalWrite(4, LOW);
        delay(200);
    }
    
    // Sound startup beep
    digitalWrite(25, HIGH);
    delay(100);
    digitalWrite(25, LOW);
    
    Serial.println("CowTag V1 Ready!");
    digitalWrite(2, HIGH); // Status LED on
}

void loop() {
    unsigned long now = millis();
    
    // Handle LoRaWAN events
    lora.loop();
    
    // Read sensors periodically
    if (now - last_sensor_read >= SENSOR_UPDATE_INTERVAL) {
        SensorData data;
        
        if (sensors.readSensors(data)) {
            // Print sensor data for debugging
            Serial.print("Accel: ");
            Serial.print(data.accel_x, 2);
            Serial.print(", ");
            Serial.print(data.accel_y, 2);
            Serial.print(", ");
            Serial.print(data.accel_z, 2);
            Serial.print(" | Temp: ");
            Serial.print(data.temperature, 1);
            Serial.print("°C | Battery: ");
            Serial.print(data.battery_voltage, 2);
            Serial.print("V");
            
            if (data.gps_valid) {
                Serial.print(" | GPS: ");
                Serial.print(data.latitude, 6);
                Serial.print(", ");
                Serial.print(data.longitude, 6);
                Serial.print(" (");
                Serial.print(data.satellites);
                Serial.print(" sats)");
            } else {
                Serial.print(" | GPS: No fix");
            }
            Serial.println();
            
            // Analyze behavior
            sensors.analyzeBehavior(data);
            AnimalBehavior behavior = sensors.getBehavior();
            
            // Print behavior analysis
            Serial.print("Behavior: ");
            if (behavior.is_moving) Serial.print("MOVING ");
            if (behavior.is_grazing) Serial.print("GRAZING ");
            if (behavior.is_resting) Serial.print("RESTING ");
            Serial.print("| Intensity: ");
            Serial.println(behavior.movement_intensity, 2);
            
            // Store data
            dataManager.addSensorData(data);
            dataManager.updateDailyStats(data, behavior);
            
        // Update movement LED based on behavior
        if (behavior.is_moving) {
            digitalWrite(18, HIGH); // Movement LED on
        } else {
            digitalWrite(18, LOW);  // Movement LED off
        }
        
        // Check emergency button
        if (digitalRead(33) == LOW) { // Button pressed (pulled low)
            Serial.println("EMERGENCY BUTTON PRESSED!");
            digitalWrite(4, HIGH);  // Emergency LED on
            digitalWrite(25, HIGH); // Buzzer on
            delay(100);
            digitalWrite(25, LOW);  // Buzzer off
            if (lora.isJoined()) {
                lora.sendEmergency(0x03); // Manual emergency code
            }
        }
            
            // Check for anomalies
            if (dataManager.isAnomalousReading(data)) {
                Serial.println("ALERT: Anomalous reading detected!");
                digitalWrite(4, HIGH); // Emergency LED on
                // Emergency alarm sequence
                for (int i = 0; i < 3; i++) {
                    digitalWrite(25, HIGH);
                    delay(100);
                    digitalWrite(25, LOW);
                    delay(100);
                }
                if (lora.isJoined()) {
                    lora.sendEmergency(0x01);
                }
            } else {
                digitalWrite(4, LOW); // Emergency LED off
            }
            
            // Update power management
            power.updateActivity();
            
        } else {
            Serial.println("Failed to read sensors");
            digitalWrite(4, HIGH); // Error LED on
        }
        
        last_sensor_read = now;
    }
    
    // Update GPS less frequently to save power
    if (now - last_gps_update >= GPS_UPDATE_INTERVAL) {
        if (sensors.updateGPS()) {
            Serial.println("GPS data updated");
        }
        last_gps_update = now;
    }
    
    // Send data via LoRaWAN
    if (now - last_lora_tx >= LORA_TX_INTERVAL && lora.isJoined()) {
        Serial.println("Sending LoRaWAN data...");
        
        SensorData latest_data;
        if (sensors.readSensors(latest_data)) {
            // Send sensor data
            if (lora.sendSensorData(latest_data)) {
                Serial.println("Sensor data sent successfully");
            } else {
                Serial.println("Failed to send sensor data");
            }
            
            // Send behavior data
            AnimalBehavior behavior = sensors.getBehavior();
            if (lora.sendBehaviorData(behavior)) {
                Serial.println("Behavior data sent successfully");
            } else {
                Serial.println("Failed to send behavior data");
            }
        }
        
        last_lora_tx = now;
    }
    
    // Power management
    power.updateBatteryLevel();
    float battery_level = power.getBatteryLevel();
    
    // Print battery status every minute
    static unsigned long last_battery_print = 0;
    if (now - last_battery_print >= 60000) {
        Serial.print("Battery level: ");
        Serial.print(battery_level, 1);
        Serial.println("%");
        last_battery_print = now;
    }
    
    // Handle low battery
    if (power.isLowBattery()) {
        Serial.println("LOW BATTERY WARNING!");
        
        // Flash error LED
        static unsigned long last_flash = 0;
        if (now - last_flash >= 1000) {
            digitalWrite(4, !digitalRead(4));
            last_flash = now;
        }
        
        if (lora.isJoined()) {
            lora.sendEmergency(0x02); // Battery emergency code
        }
        power.setMode(POWER_LOW);
    }
    
    // Print daily stats every 10 minutes
    static unsigned long last_stats_print = 0;
    if (now - last_stats_print >= 600000) {
        DailyStats stats = dataManager.getDailyStats();
        Serial.println("\n=== Daily Stats ===");
        Serial.print("Movement time: ");
        Serial.print(stats.total_movement_time);
        Serial.println(" seconds");
        Serial.print("Grazing time: ");
        Serial.print(stats.total_grazing_time);
        Serial.println(" seconds");
        Serial.print("Rest time: ");
        Serial.print(stats.total_rest_time);
        Serial.println(" seconds");
        Serial.print("Distance traveled: ");
        Serial.print(stats.distance_traveled);
        Serial.println(" meters");
        Serial.print("Health score: ");
        Serial.println(stats.health_score);
        Serial.println("==================\n");
        last_stats_print = now;
    }
    
    // Check if should enter sleep mode
    if (power.shouldSleep()) {
        Serial.println("Entering deep sleep mode...");
        Serial.flush(); // Ensure all serial data is sent
        power.enterDeepSleep(SLEEP_TIME_US);
        // Device will restart after deep sleep
    }
    
    // Small delay to prevent overwhelming the serial output
    delay(100);
}