#ifndef COWTAG_POWER_H
#define COWTAG_POWER_H

#include <esp_sleep.h>
#include <esp_wifi.h>
#include <esp_bt.h>

enum PowerMode {
    POWER_ACTIVE,
    POWER_LOW,
    POWER_DEEP_SLEEP,
    POWER_EMERGENCY
};

class CowTagPower {
private:
    PowerMode current_mode;
    uint32_t last_activity_time;
    float battery_level;
    bool low_battery_warning;
    
public:
    CowTagPower();
    void begin();
    void setMode(PowerMode mode);
    PowerMode getMode();
    void updateBatteryLevel();
    float getBatteryLevel();
    bool isLowBattery();
    void enterDeepSleep(uint64_t time_us);
    void disablePeripherals();
    void enablePeripherals();
    void updateActivity();
    bool shouldSleep();
};

#endif