#include <assert.h>
#include <iostream>

#define TEMPERATURE_LOWER_BOUNDARY  (0)
#define TEMPERATURE_UPPER_BOUNDARY  (45)
#define SOC_LOWER_BOUNDARY          (20)
#define SOC_UPPER_BOUNDARY          (80)
const float CHARGE_RATE_BOUNDARY = 0.8;

using namespace     std;

bool isBatteryTemperatureOk(float temperature);
bool isBatteryStateOfChargeOk(float soc);
bool isBatteryChargeRateOk(float chargeRate);

bool isBatteryTemperatureOk(float temperature){
  bool temperatureReturn = true;
  if((temperature < TEMPERATURE_LOWER_BOUNDARY) || (temperature > TEMPERATURE_UPPER_BOUNDARY)) {
    cout << "Temperature out of range!\n";
    temperatureReturn = false;
  }
  return temperatureReturn;
}

bool isBatteryStateOfChargeOk(float soc){
  bool socReturn = true;
  if((soc < SOC_LOWER_BOUNDARY) || (soc > SOC_UPPER_BOUNDARY)) {
    cout << "State of Charge out of range!\n";
    socReturn = false;
  }
  return socReturn;
}

bool isBatteryChargeRateOk(float chargeRate){
  bool chargeRateReturn = true;
  if(chargeRate > CHARGE_RATE_BOUNDARY) {
    cout << "Charge Rate out of range!\n";
    chargeRateReturn = false;
  }
  return chargeRateReturn;
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
