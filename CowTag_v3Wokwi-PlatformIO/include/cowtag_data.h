#ifndef COWTAG_DATA_H
#define COWTAG_DATA_H

#include <Arduino.h>
#include <ArduinoJson.h>

// Forward declarations to avoid circular dependency
struct SensorData;
struct AnimalBehavior;

// Constants
#define MAX_DATA_POINTS 50

struct DailyStats {
    uint32_t total_movement_time;
    uint32_t total_grazing_time;
    uint32_t total_rest_time;
    float max_movement_intensity;
    float avg_temperature;
    uint16_t distance_traveled;
    uint8_t health_score;
};

class CowTagData {
private:
    SensorData* data_buffer;  // Dynamic array
    uint8_t buffer_index;
    uint8_t buffer_count;
    DailyStats daily_stats;
    uint32_t day_start_time;
    
public:
    CowTagData();
    ~CowTagData();
    void addSensorData(const SensorData &data);
    void updateDailyStats(const SensorData &data, const AnimalBehavior &behavior);
    DailyStats getDailyStats();
    void resetDailyStats();
    uint8_t calculateHealthScore();
    String generateDataPacket();
    bool isAnomalousReading(const SensorData &data);
    float calculateDistance(double lat1, double lon1, double lat2, double lon2);
};

#endif