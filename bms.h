#ifndef __BMS_H_
#define __BMS_H_

#include <vector>
#include <string>

class Battery{
  public:
    const float TEMPERATURE_LOWER_BOUNDARY = 0;
    const float TEMPERATURE_UPPER_BOUNDARY = 45;
    const float SOC_LOWER_BOUNDARY = 20;
    const float SOC_UPPER_BOUNDARY = 80;
    const float CHARGE_RATE_LOWER_BOUNDARY = 0.0;
    const float CHARGE_RATE_UPPER_BOUNDARY = 0.8;

    typedef enum BMS_PARAMETER
    {
        BATTERY_TEMPERATURE = 0,
        BATTERY_SOC,
        BATTERY_CHARGE_RATE
    };

    typedef enum BREACH_TYPE
    {
       LOW_BREACH = 0,
       HIGH_BREACH,
       OUT_OF_RANGE
    };

    typedef enum CRITICALITY{
      WARNING,
      ERROR
    };

    typedef enum LANGUAGE{
      ENGLISH = 0,
      GERMAN,
    };

    const int logLanguage = ENGLISH; /*for language change change enum*/
    //const int logLanguage = GERMAN;

    std::vector<std::vector<std::string>> batteryParameter = { { "Temperature", "State of charge", "Charge Rate" }, {"Temperatur", "Ladezustand", "Ladestrom"} };
    std::vector<std::vector<std::string>> batteryBreach = {{ "Low", "High", "Out Of Range" } ,{"niedrig", "hoch", "Auﬂer Reichweite"}};
    std::vector<std::vector<std::string>> batteryBreachCriticality = {{ "Warning", "Error" },{"Warnung","Error"}};
};

class BatteryManagementSystem : public Battery{
  public:
    bool isBatteryTemperatureOk(float temperature, BMS_PARAMETER bmsParameter);
    bool isBatteryStateOfChargeOk(float soc, BMS_PARAMETER bmsParameter);
    bool isBatteryChargeRateOk(float chargeRate, BMS_PARAMETER bmsParameter);
    void bmsLowWarning(float value, float lowerBoundary, float upperBoundary, BMS_PARAMETER bmsParameter);
    void bmsHighWarning(float value, float upperBoundary, BMS_PARAMETER bmsParameter);
    void bmsDisplyMessage(BMS_PARAMETER bmsPparameter, BREACH_TYPE breachType, CRITICALITY criticality);
};

#endif /*__BMS_H_*/
