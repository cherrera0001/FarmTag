#include <Arduino.h>
#include <SPI.h>
#include <lmic.h>
#include <hal/hal.h>
#include "cowtag_lora.h"
#include "cowtag_config.h"

// Static instance pointer for callback
CowTagLoRa* CowTagLoRa::instance = nullptr;

// Pin mapping for TTGO T-Beam
const lmic_pinmap lmic_pins = {
    .nss = LORA_CS_PIN,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = LORA_RST_PIN,
    .dio = {LORA_DIO0_PIN, LORA_DIO1_PIN, LORA_DIO2_PIN},
};

// LoRaWAN credentials (required by LMIC)
void os_getArtEui (u1_t* buf) {
    static const u1_t APPEUI[8] = LORAWAN_APP_EUI;
    memcpy(buf, APPEUI, 8);
}

void os_getDevEui (u1_t* buf) {
    static const u1_t DEVEUI[8] = LORAWAN_DEV_EUI;
    memcpy(buf, DEVEUI, 8);
}

void os_getDevKey (u1_t* buf) {
    static const u1_t APPKEY[16] = LORAWAN_APP_KEY;
    memcpy(buf, APPKEY, 16);
}

CowTagLoRa::CowTagLoRa() {
    instance = this;
    joined = false;
    last_tx_time = 0;
}

bool CowTagLoRa::begin() {
    // Initialize LMIC
    os_init();
    
    // Reset MAC state
    LMIC_reset();
    
    // Set static session parameters for ABP (simplified for demo)
    uint8_t appskey[16] = LORAWAN_APP_KEY;
    uint8_t nwkskey[16] = LORAWAN_APP_KEY;
    uint32_t devaddr = 0x12345678;
    
    LMIC_setSession(0x13, devaddr, nwkskey, appskey);
    
    // Set up channels (EU868)
    #if defined(CFG_eu868)
    LMIC_setupChannel(0, 868100000, DR_RANGE_MAP(DR_SF12, DR_SF7), BAND_CENTI);
    LMIC_setupChannel(1, 868300000, DR_RANGE_MAP(DR_SF12, DR_SF7B), BAND_CENTI);
    LMIC_setupChannel(2, 868500000, DR_RANGE_MAP(DR_SF12, DR_SF7), BAND_CENTI);
    #endif
    
    // Disable link check validation
    LMIC_setLinkCheckMode(0);
    
    // Set data rate and transmit power
    LMIC_setDrTxpow(DR_SF7, 14);
    
    joined = true; // For ABP mode
    
    Serial.println("LoRaWAN initialized (ABP mode)");
    return true;
}

void CowTagLoRa::loop() {
    os_runloop_once();
}

bool CowTagLoRa::sendSensorData(const SensorData &data) {
    if (!joined || (millis() - last_tx_time) < 30000) {
        return false;
    }
    
    LoRaMessage msg;
    msg.message_type = MSG_SENSOR_DATA;
    msg.device_id = 0x1234;
    msg.timestamp = data.timestamp;
    
    // Pack sensor data (simplified)
    uint8_t *ptr = msg.data;
    
    // GPS coordinates (4 bytes each)
    int32_t lat = (int32_t)(data.latitude * 1000000);
    int32_t lon = (int32_t)(data.longitude * 1000000);
    memcpy(ptr, &lat, 4); ptr += 4;
    memcpy(ptr, &lon, 4); ptr += 4;
    
    // Temperature (1 byte)
    int8_t temp = (int8_t)data.temperature;
    *ptr++ = temp;
    
    // Battery voltage (1 byte, scaled)
    uint8_t battery = (uint8_t)((data.battery_voltage - 3.0) * 100);
    *ptr++ = battery;
    
    msg.data_length = ptr - msg.data;
    
    // Encode and send
    uint8_t buffer[32];
    uint8_t length;
    encodeMessage(msg, buffer, length);
    
    if (LMIC.opmode & OP_TXRXPEND) {
        return false;
    }
    
    LMIC_setTxData2(1, buffer, length, 0);
    last_tx_time = millis();
    
    return true;
}

bool CowTagLoRa::sendBehaviorData(const AnimalBehavior &behavior) {
    if (!joined || (millis() - last_tx_time) < 30000) {
        return false;
    }
    
    LoRaMessage msg;
    msg.message_type = MSG_BEHAVIOR_DATA;
    msg.device_id = 0x1234;
    msg.timestamp = millis();
    
    uint8_t *ptr = msg.data;
    
    // Behavior flags
    uint8_t flags = 0;
    if (behavior.is_moving) flags |= 0x01;
    if (behavior.is_grazing) flags |= 0x02;
    if (behavior.is_resting) flags |= 0x04;
    *ptr++ = flags;
    
    // Movement intensity (1 byte, scaled)
    uint8_t intensity = (uint8_t)(behavior.movement_intensity * 100);
    *ptr++ = intensity;
    
    msg.data_length = ptr - msg.data;
    
    uint8_t buffer[32];
    uint8_t length;
    encodeMessage(msg, buffer, length);
    
    if (LMIC.opmode & OP_TXRXPEND) {
        return false;
    }
    
    LMIC_setTxData2(2, buffer, length, 0);
    last_tx_time = millis();
    
    return true;
}

bool CowTagLoRa::sendEmergency(uint8_t emergency_code) {
    LoRaMessage msg;
    msg.message_type = MSG_EMERGENCY;
    msg.device_id = 0x1234;
    msg.timestamp = millis();
    msg.data[0] = emergency_code;
    msg.data_length = 1;
    
    uint8_t buffer[32];
    uint8_t length;
    encodeMessage(msg, buffer, length);
    
    // Emergency messages have priority
    LMIC_setTxData2(3, buffer, length, 0);
    last_tx_time = millis();
    
    return true;
}

bool CowTagLoRa::sendHeartbeat() {
    if (!joined || (millis() - last_tx_time) < 60000) {
        return false;
    }
    
    LoRaMessage msg;
    msg.message_type = MSG_HEARTBEAT;
    msg.device_id = 0x1234;
    msg.timestamp = millis();
    msg.data_length = 0;
    
    uint8_t buffer[32];
    uint8_t length;
    encodeMessage(msg, buffer, length);
    
    LMIC_setTxData2(4, buffer, length, 0);
    last_tx_time = millis();
    
    return true;
}

bool CowTagLoRa::isJoined() {
    return joined;
}

void CowTagLoRa::encodeMessage(const LoRaMessage &msg, uint8_t *buffer, uint8_t &length) {
    uint8_t *ptr = buffer;
    
    *ptr++ = msg.message_type;
    memcpy(ptr, &msg.device_id, 2); ptr += 2;
    memcpy(ptr, &msg.timestamp, 4); ptr += 4;
    *ptr++ = msg.data_length;
    memcpy(ptr, msg.data, msg.data_length); ptr += msg.data_length;
    
    length = ptr - buffer;
}

void CowTagLoRa::onEvent(ev_t ev) {
    if (instance) {
        instance->handleEvent(ev);
    }
}

void CowTagLoRa::handleEvent(ev_t ev) {
    switch(ev) {
        case EV_SCAN_TIMEOUT:
            Serial.println(F("EV_SCAN_TIMEOUT"));
            break;
        case EV_BEACON_FOUND:
            Serial.println(F("EV_BEACON_FOUND"));
            break;
        case EV_BEACON_MISSED:
            Serial.println(F("EV_BEACON_MISSED"));
            break;
        case EV_BEACON_TRACKED:
            Serial.println(F("EV_BEACON_TRACKED"));
            break;
        case EV_JOINING:
            Serial.println(F("EV_JOINING"));
            break;
        case EV_JOINED:
            Serial.println(F("EV_JOINED"));
            joined = true;
            break;
        case EV_JOIN_FAILED:
            Serial.println(F("EV_JOIN_FAILED"));
            break;
        case EV_REJOIN_FAILED:
            Serial.println(F("EV_REJOIN_FAILED"));
            break;
        case EV_TXCOMPLETE:
            Serial.println(F("EV_TXCOMPLETE"));
            if (LMIC.txrxFlags & TXRX_ACK)
                Serial.println(F("Received ack"));
            if (LMIC.dataLen) {
                Serial.print(F("Received "));
                Serial.print(LMIC.dataLen);
                Serial.println(F(" bytes of payload"));
            }
            break;
        case EV_LOST_TSYNC:
            Serial.println(F("EV_LOST_TSYNC"));
            break;
        case EV_RESET:
            Serial.println(F("EV_RESET"));
            break;
        case EV_RXCOMPLETE:
            Serial.println(F("EV_RXCOMPLETE"));
            break;
        case EV_LINK_DEAD:
            Serial.println(F("EV_LINK_DEAD"));
            break;
        case EV_LINK_ALIVE:
            Serial.println(F("EV_LINK_ALIVE"));
            break;
        case EV_TXSTART:
            Serial.println(F("EV_TXSTART"));
            break;
        default:
            Serial.print(F("Unknown event: "));
            Serial.println((unsigned) ev);
            break;
    }
}