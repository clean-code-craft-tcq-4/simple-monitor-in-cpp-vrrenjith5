#include <assert.h>
#include <iostream>
#include "bms.h"

using namespace std;

int main()
{
  BatteryManagementSystem bmsObject;
  Battery batteryObject;

  assert(bmsObject.isBatteryTemperatureOk(batteryObject.TEMPERATURE_LOWER_BOUNDARY - 1, batteryObject.BATTERY_TEMPERATURE) == false);
  assert(bmsObject.isBatteryTemperatureOk(batteryObject.TEMPERATURE_LOWER_BOUNDARY, batteryObject.BATTERY_TEMPERATURE) == true);
  assert(bmsObject.isBatteryTemperatureOk(batteryObject.TEMPERATURE_LOWER_BOUNDARY + 1, batteryObject.BATTERY_TEMPERATURE) == true);
  assert(bmsObject.isBatteryTemperatureOk(batteryObject.TEMPERATURE_UPPER_BOUNDARY - 1,batteryObject.BATTERY_TEMPERATURE) == true);
  assert(bmsObject.isBatteryTemperatureOk(batteryObject.TEMPERATURE_UPPER_BOUNDARY, batteryObject.BATTERY_TEMPERATURE) == true);
  assert(bmsObject.isBatteryTemperatureOk(batteryObject.TEMPERATURE_UPPER_BOUNDARY + 1, batteryObject.BATTERY_TEMPERATURE) == false);

  assert(bmsObject.isBatteryStateOfChargeOk(batteryObject.SOC_LOWER_BOUNDARY - 1, batteryObject.BATTERY_SOC) == false);
  assert(bmsObject.isBatteryStateOfChargeOk(batteryObject.SOC_LOWER_BOUNDARY, batteryObject.BATTERY_SOC) == true);
  assert(bmsObject.isBatteryStateOfChargeOk(batteryObject.SOC_LOWER_BOUNDARY + 1, batteryObject.BATTERY_SOC) == true);
  assert(bmsObject.isBatteryStateOfChargeOk(batteryObject.SOC_UPPER_BOUNDARY - 1, batteryObject.BATTERY_SOC) == true);
  assert(bmsObject.isBatteryStateOfChargeOk(batteryObject.SOC_UPPER_BOUNDARY, batteryObject.BATTERY_SOC) == true);
  assert(bmsObject.isBatteryStateOfChargeOk(batteryObject.SOC_UPPER_BOUNDARY + 1, batteryObject.BATTERY_SOC) == false);

  assert(bmsObject.isBatteryChargeRateOk(0.01, batteryObject.BATTERY_CHARGE_RATE) == true);
  assert(bmsObject.isBatteryChargeRateOk(0.77, batteryObject.BATTERY_CHARGE_RATE) == true);
  assert(bmsObject.isBatteryChargeRateOk(batteryObject.CHARGE_RATE_UPPER_BOUNDARY, batteryObject.BATTERY_CHARGE_RATE) == true);
  assert(bmsObject.isBatteryChargeRateOk(batteryObject.CHARGE_RATE_UPPER_BOUNDARY + 0.1, batteryObject.BATTERY_CHARGE_RATE) == false);

  return 0;
}
