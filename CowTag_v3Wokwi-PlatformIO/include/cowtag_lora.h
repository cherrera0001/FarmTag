#ifndef COWTAG_LORA_H
#define COWTAG_LORA_H

#include <lmic.h>
#include <hal/hal.h>
#include <SPI.h>
#include "cowtag_sensors.h"

enum MessageType {
    MSG_SENSOR_DATA = 0x01,
    MSG_BEHAVIOR_DATA = 0x02,
    MSG_EMERGENCY = 0x03,
    MSG_HEARTBEAT = 0x04
};

struct LoRaMessage {
    uint8_t message_type;
    uint16_t device_id;
    uint32_t timestamp;
    uint8_t data[20];
    uint8_t data_length;
};

class CowTagLoRa {
private:
    static CowTagLoRa* instance;
    bool joined;
    uint32_t last_tx_time;
    uint8_t tx_buffer[32];
    
    static void onEvent(ev_t ev);
    void handleEvent(ev_t ev);
    
public:
    CowTagLoRa();
    bool begin();
    void loop();
    bool sendSensorData(const SensorData &data);
    bool sendBehaviorData(const AnimalBehavior &behavior);
    bool sendEmergency(uint8_t emergency_code);
    bool sendHeartbeat();
    bool isJoined();
    void encodeMessage(const LoRaMessage &msg, uint8_t *buffer, uint8_t &length);
};

#endif