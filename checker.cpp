#include <assert.h>
#include <iostream>

using namespace     std;
const float TEMPERATURE_LOWER_BOUNDARY = 0;
const float TEMPERATURE_UPPER_BOUNDARY = 45;
const float SOC_LOWER_BOUNDARY = 20;
const float SOC_UPPER_BOUNDARY = 80;
const float CHARGE_RATE_BOUNDARY = 0.8;

bool isBatteryTemperatureOk(float temperature);
bool isBatteryStateOfChargeOk(float soc);
bool isBatteryChargeRateOk(float chargeRate);

static inline bool isLessThanOrEqual(float firstValue, float secondValue){
 return ((firstValue <= secondValue)?(true):(false));
}

static inline bool isInRange(float value, float lowerBoundary, float upperBoundary){
 return (isLessThanOrEqual(lowerBoundary, value) && isLessThanOrEqual(value, upperBoundary));
}

bool isBatteryTemperatureOk(float temperature){
 bool result = isInRange(temperature, TEMPERATURE_LOWER_BOUNDARY, TEMPERATURE_UPPER_BOUNDARY);
 if(!result) {
   cout << "Temperature out of range!\n";
 }
 return result;
}

bool isBatteryStateOfChargeOk(float soc){
 bool result = isInRange(soc, SOC_LOWER_BOUNDARY, SOC_UPPER_BOUNDARY);
 if(!result) {
   cout << "State of Charge out of range!\n";
 }
 return result;
}

bool isBatteryChargeRateOk(float chargeRate){
  bool result = isLessThanOrEqual(chargeRate, CHARGE_RATE_BOUNDARY);
  if(!result) {
    cout << "Charge Rate out of range!\n";
  }
  return result;
}

int main() {
  assert(isBatteryTemperatureOk(TEMPERATURE_LOWER_BOUNDARY - 1) == false);
  assert(isBatteryTemperatureOk(TEMPERATURE_LOWER_BOUNDARY) == true);
  assert(isBatteryTemperatureOk(TEMPERATURE_LOWER_BOUNDARY + 1) == true);
  assert(isBatteryTemperatureOk(TEMPERATURE_UPPER_BOUNDARY - 1) == true);
  assert(isBatteryTemperatureOk(TEMPERATURE_UPPER_BOUNDARY) == true);
  assert(isBatteryTemperatureOk(TEMPERATURE_UPPER_BOUNDARY + 1) == false);

  assert(isBatteryStateOfChargeOk(SOC_LOWER_BOUNDARY - 1) == false);
  assert(isBatteryStateOfChargeOk(SOC_LOWER_BOUNDARY) == true);
  assert(isBatteryStateOfChargeOk(SOC_LOWER_BOUNDARY + 1) == true);
  assert(isBatteryStateOfChargeOk(SOC_UPPER_BOUNDARY - 1) == true);
  assert(isBatteryStateOfChargeOk(SOC_UPPER_BOUNDARY) == true);
  assert(isBatteryStateOfChargeOk(SOC_UPPER_BOUNDARY + 1) == false);

  assert(isBatteryChargeRateOk(CHARGE_RATE_BOUNDARY - 1) == true);
  assert(isBatteryChargeRateOk(CHARGE_RATE_BOUNDARY) == true);
  assert(isBatteryChargeRateOk(CHARGE_RATE_BOUNDARY +1) == false);
}
