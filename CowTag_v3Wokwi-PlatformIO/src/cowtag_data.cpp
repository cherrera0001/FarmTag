#include <Arduino.h>
#include <ArduinoJson.h>
#include <math.h>
#include "cowtag_data.h"
#include "cowtag_sensors.h"
#include "cowtag_config.h"

CowTagData::CowTagData() {
    buffer_index = 0;
    buffer_count = 0;
    day_start_time = millis();
    
    // Allocate memory for data buffer
    data_buffer = new SensorData[MAX_DATA_POINTS];
    
    resetDailyStats();
}

CowTagData::~CowTagData() {
    delete[] data_buffer;
}

void CowTagData::addSensorData(const SensorData &data) {
    // Add data to circular buffer
    data_buffer[buffer_index] = data;
    buffer_index = (buffer_index + 1) % MAX_DATA_POINTS;
    
    if (buffer_count < MAX_DATA_POINTS) {
        buffer_count++;
    }
}

void CowTagData::updateDailyStats(const SensorData &data, const AnimalBehavior &behavior) {
    uint32_t current_time = millis();
    
    // Check if it's a new day (24 hours passed)
    if (current_time - day_start_time > 86400000) { // 24 hours in milliseconds
        resetDailyStats();
        day_start_time = current_time;
    }
    
    // Update movement time
    if (behavior.is_moving) {
        daily_stats.total_movement_time += 5; // 5 seconds interval
    }
    
    // Update grazing time
    if (behavior.is_grazing) {
        daily_stats.total_grazing_time += 5;
    }
    
    // Update rest time
    if (behavior.is_resting) {
        daily_stats.total_rest_time += 5;
    }
    
    // Update maximum movement intensity
    if (behavior.movement_intensity > daily_stats.max_movement_intensity) {
        daily_stats.max_movement_intensity = behavior.movement_intensity;
    }
    
    // Update average temperature
    static float temp_sum = 0;
    static uint32_t temp_count = 0;
    temp_sum += data.temperature;
    temp_count++;
    daily_stats.avg_temperature = temp_sum / temp_count;
    
    // Update health score
    daily_stats.health_score = calculateHealthScore();
}

DailyStats CowTagData::getDailyStats() {
    return daily_stats;
}

void CowTagData::resetDailyStats() {
    daily_stats.total_movement_time = 0;
    daily_stats.total_grazing_time = 0;
    daily_stats.total_rest_time = 0;
    daily_stats.max_movement_intensity = 0;
    daily_stats.avg_temperature = 0;
    daily_stats.distance_traveled = 0;
    daily_stats.health_score = 100;
}

uint8_t CowTagData::calculateHealthScore() {
    uint8_t score = 100;
    
    // Simple health calculation
    if (daily_stats.avg_temperature > 40.0 || daily_stats.avg_temperature < 35.0) {
        score -= 15;
    }
    
    if (daily_stats.max_movement_intensity < 1.0) {
        score -= 10;
    }
    
    if (score > 100) score = 0;
    
    return score;
}

String CowTagData::generateDataPacket() {
    DynamicJsonDocument doc(512);
    
    doc["device_id"] = "COWTAG_001";
    doc["timestamp"] = millis();
    doc["daily_stats"]["movement_time"] = daily_stats.total_movement_time;
    doc["daily_stats"]["grazing_time"] = daily_stats.total_grazing_time;
    doc["daily_stats"]["rest_time"] = daily_stats.total_rest_time;
    doc["daily_stats"]["health_score"] = daily_stats.health_score;
    
    String output;
    serializeJson(doc, output);
    return output;
}

bool CowTagData::isAnomalousReading(const SensorData &data) {
    // Check for extreme temperature readings
    if (data.temperature > 45.0 || data.temperature < 30.0) {
        return true;
    }
    
    // Check for extremely high acceleration
    float accel_magnitude = sqrt(data.accel_x * data.accel_x + 
                                data.accel_y * data.accel_y + 
                                data.accel_z * data.accel_z);
    if (accel_magnitude > 20.0) {
        return true;
    }
    
    // Check for very low battery
    if (data.battery_voltage < 3.2) {
        return true;
    }
    
    return false;
}

float CowTagData::calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const float R = 6371000; // Earth's radius in meters
    
    double dLat = (lat2 - lat1) * PI / 180.0;
    double dLon = (lon2 - lon1) * PI / 180.0;
    
    double a = sin(dLat/2) * sin(dLat/2) +
               cos(lat1 * PI / 180.0) * cos(lat2 * PI / 180.0) *
               sin(dLon/2) * sin(dLon/2);
    
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    
    return R * c;
}