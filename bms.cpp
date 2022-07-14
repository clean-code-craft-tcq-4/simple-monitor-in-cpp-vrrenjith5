#include <iostream>
#include "bms.h"
#include "comparison.h"

using namespace std;
Comparison comparisonObject;

void BatteryManagementSystem :: bmsDisplyMessage(BMS_PARAMETER bmsPparameter, BREACH_TYPE breachType, CRITICALITY criticality)
{
  cout << batteryBreach[logLanguage][breachType] << " " << batteryParameter[logLanguage][bmsPparameter] <<" "<< batteryBreachCriticality[logLanguage][criticality]<<endl;
}

void BatteryManagementSystem :: bmsLowWarning(float value, float lowerBoundary, float upperBoundary, BMS_PARAMETER bmsParameter)
{
    float bmsTolerance = (5*upperBoundary) / 100;
    if((comparisonObject.isGreaterThan(value, lowerBoundary))&& (comparisonObject.isLessThan(value , (lowerBoundary + bmsTolerance))))
    {
        bmsDisplyMessage(bmsParameter, LOW_BREACH, WARNING);
    }
}

void BatteryManagementSystem :: bmsHighWarning(float value, float upperBoundary, BMS_PARAMETER bmsParameter)
{
    float bmsTolerance = (5*upperBoundary) / 100;
    if((comparisonObject.isGreaterThan(value, (upperBoundary - bmsTolerance)))&& (comparisonObject.isLessThan(value , upperBoundary)))
    {
        bmsDisplyMessage(bmsParameter, HIGH_BREACH, WARNING);
    }
}

bool BatteryManagementSystem :: isBatteryTemperatureOk(float temperature, BMS_PARAMETER bmsParameter){
 bool result = comparisonObject.isWithInRange(temperature, TEMPERATURE_LOWER_BOUNDARY, TEMPERATURE_UPPER_BOUNDARY);
 bmsLowWarning(temperature, TEMPERATURE_LOWER_BOUNDARY, TEMPERATURE_UPPER_BOUNDARY, BATTERY_TEMPERATURE);
 bmsHighWarning(temperature, TEMPERATURE_UPPER_BOUNDARY, BATTERY_TEMPERATURE);
 if(!result) {
   bmsDisplyMessage(bmsParameter, OUT_OF_RANGE, ERROR);
 }
 return result;
}

bool BatteryManagementSystem :: isBatteryStateOfChargeOk(float soc, BMS_PARAMETER bmsParameter){
 bool result = comparisonObject.isWithInRange(soc, SOC_LOWER_BOUNDARY, SOC_UPPER_BOUNDARY);
 bmsLowWarning(soc, SOC_LOWER_BOUNDARY, SOC_UPPER_BOUNDARY, BATTERY_SOC);
 bmsHighWarning(soc, SOC_UPPER_BOUNDARY, BATTERY_SOC);
 if(!result) {
   bmsDisplyMessage(bmsParameter, OUT_OF_RANGE, ERROR);
 }
 return result;
}

bool BatteryManagementSystem :: isBatteryChargeRateOk(float chargeRate, BMS_PARAMETER bmsParameter){
  bool result = comparisonObject.isWithInRange(chargeRate, CHARGE_RATE_LOWER_BOUNDARY,CHARGE_RATE_UPPER_BOUNDARY);
  bmsLowWarning(chargeRate, CHARGE_RATE_LOWER_BOUNDARY, CHARGE_RATE_UPPER_BOUNDARY, BATTERY_CHARGE_RATE);
  bmsHighWarning(chargeRate, CHARGE_RATE_UPPER_BOUNDARY, BATTERY_CHARGE_RATE);
  if(!result) {
    bmsDisplyMessage(bmsParameter, OUT_OF_RANGE, ERROR);
  }
  return result;
}
