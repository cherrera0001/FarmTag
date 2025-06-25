#ifndef COWTAG_SENSORS_H
#define COWTAG_SENSORS_H

#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>

struct SensorData {
    float accel_x, accel_y, accel_z;
    float gyro_x, gyro_y, gyro_z;
    float temperature;
    double latitude, longitude;
    float altitude;
    uint8_t satellites;
    bool gps_valid;
    uint32_t timestamp;
    float battery_voltage;
};

struct AnimalBehavior {
    bool is_moving;
    bool is_grazing;
    bool is_resting;
    uint32_t last_movement_time;
    uint32_t movement_duration;
    uint32_t rest_duration;
    float movement_intensity;
};

class CowTagSensors {
private:
    Adafruit_MPU6050 mpu;
    TinyGPSPlus gps;
    HardwareSerial gpsSerial;
    SensorData last_reading;
    AnimalBehavior behavior;
    
public:
    CowTagSensors();
    bool begin();
    bool readSensors(SensorData &data);
    bool updateGPS();
    void analyzeBehavior(const SensorData &data);
    AnimalBehavior getBehavior();
    float calculateMovementIntensity(const SensorData &data);
    float readBatteryVoltage();
};

#endif