#ifndef COWTAG_CONFIG_H
#define COWTAG_CONFIG_H

// LoRaWAN Configuration
#define LORAWAN_APP_EUI  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
#define LORAWAN_DEV_EUI  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
#define LORAWAN_APP_KEY  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}

// Pin Configuration for TTGO T-Beam
#define GPS_RX_PIN          12
#define GPS_TX_PIN          15
#define MPU6050_SDA_PIN     21
#define MPU6050_SCL_PIN     22
#define LORA_SCK_PIN        5
#define LORA_MISO_PIN       19
#define LORA_MOSI_PIN       27
#define LORA_CS_PIN         18
#define LORA_RST_PIN        14
#define LORA_DIO0_PIN       26
#define LORA_DIO1_PIN       33
#define LORA_DIO2_PIN       32

// Timing Configuration
#define GPS_UPDATE_INTERVAL     30000   // 30 seconds
#define SENSOR_UPDATE_INTERVAL  5000    // 5 seconds
#define LORA_TX_INTERVAL       300000   // 5 minutes
#define SLEEP_TIME_US          30000000 // 30 seconds

// Behavioral Thresholds
#define MOVEMENT_THRESHOLD      2.0     // g-force threshold
#define GRAZING_TIME_MIN        1800    // 30 minutes in seconds
#define REST_TIME_MIN           3600    // 1 hour in seconds

// Data Storage
#define MAX_DATA_POINTS         50
#define EMERGENCY_BATTERY_LEVEL 20      // 20% battery

#endif