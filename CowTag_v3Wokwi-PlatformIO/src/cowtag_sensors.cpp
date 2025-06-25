#include <Arduino.h>
#include <Wire.h>
#include <HardwareSerial.h>
#include <math.h>
#include "cowtag_sensors.h"
#include "cowtag_config.h"

CowTagSensors::CowTagSensors() : gpsSerial(2) {
    // Initialize behavior struct
    behavior.is_moving = false;
    behavior.is_grazing = false;
    behavior.is_resting = true;
    behavior.last_movement_time = 0;
    behavior.movement_duration = 0;
    behavior.rest_duration = 0;
    behavior.movement_intensity = 0;
}

bool CowTagSensors::begin() {
    // Initialize I2C
    Wire.begin(MPU6050_SDA_PIN, MPU6050_SCL_PIN);
    
    // Initialize MPU6050
    if (!mpu.begin()) {
        Serial.println("Failed to find MPU6050 chip");
        return false;
    }
    
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    
    // Initialize GPS
    gpsSerial.begin(9600, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
    
    Serial.println("CowTag sensors initialized");
    return true;
}

bool CowTagSensors::readSensors(SensorData &data) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    
    // Read accelerometer data
    data.accel_x = a.acceleration.x;
    data.accel_y = a.acceleration.y;
    data.accel_z = a.acceleration.z;
    
    // Read gyroscope data
    data.gyro_x = g.gyro.x;
    data.gyro_y = g.gyro.y;
    data.gyro_z = g.gyro.z;
    
    // Read temperature
    data.temperature = temp.temperature;
    
    // Read battery voltage
    data.battery_voltage = readBatteryVoltage();
    
    // Set timestamp
    data.timestamp = millis();
    
    // GPS data (if available)
    if (gps.location.isValid()) {
        data.latitude = gps.location.lat();
        data.longitude = gps.location.lng();
        data.altitude = gps.altitude.meters();
        data.satellites = gps.satellites.value();
        data.gps_valid = true;
    } else {
        data.gps_valid = false;
        data.satellites = 0;
    }
    
    // Store last reading
    last_reading = data;
    
    return true;
}

bool CowTagSensors::updateGPS() {
    while (gpsSerial.available() > 0) {
        if (gps.encode(gpsSerial.read())) {
            return true;
        }
    }
    return false;
}

void CowTagSensors::analyzeBehavior(const SensorData &data) {
    float movement_intensity = calculateMovementIntensity(data);
    uint32_t current_time = millis();
    
    // Determine if animal is moving
    if (movement_intensity > MOVEMENT_THRESHOLD) {
        if (!behavior.is_moving) {
            // Just started moving
            behavior.is_moving = true;
            behavior.is_resting = false;
            behavior.is_grazing = false;
            behavior.last_movement_time = current_time;
        }
        behavior.movement_duration = current_time - behavior.last_movement_time;
    } else {
        // Animal is not moving significantly
        if (behavior.is_moving) {
            // Just stopped moving
            behavior.is_moving = false;
            
            // Determine if grazing or resting based on duration and position
            if (movement_intensity > 0.5) {
                behavior.is_grazing = true;
                behavior.is_resting = false;
            } else {
                behavior.is_grazing = false;
                behavior.is_resting = true;
            }
        }
        
        if (behavior.is_resting) {
            behavior.rest_duration = current_time - behavior.last_movement_time;
        }
    }
    
    behavior.movement_intensity = movement_intensity;
}

AnimalBehavior CowTagSensors::getBehavior() {
    return behavior;
}

float CowTagSensors::calculateMovementIntensity(const SensorData &data) {
    // Calculate magnitude of acceleration vector
    float magnitude = sqrt(data.accel_x * data.accel_x + 
                          data.accel_y * data.accel_y + 
                          data.accel_z * data.accel_z);
    
    // Subtract gravity (9.8 m/s²) to get movement component
    float movement = abs(magnitude - 9.8);
    
    return movement;
}

float CowTagSensors::readBatteryVoltage() {
    // For TTGO T-Beam, battery voltage is on pin 35
    int raw = analogRead(35);
    float voltage = (raw / 4095.0) * 2 * 3.3 * 1.1; // Voltage divider compensation
    return voltage;
}