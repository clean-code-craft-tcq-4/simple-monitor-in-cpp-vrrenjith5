#include <assert.h>
#include <iostream>

typedef enum Language{
  English = 0,
  German,
};

static int logLanguage = English;

using namespace     std;

class Comparison{
  public:
    bool isLessThanOrEqual(float value, float boundary);
    bool isGreaterThanOrEqual(float value, float boundary);
    bool isInRange(float value, float lowerBoundary, float upperBoundary);
};

bool Comparison :: isLessThanOrEqual(float value, float boundary){
 bool result = ((value <= boundary)?(true):(false));
 if (!result){
   cout<<"value is greater than boundary"<<endl;
 }
 return result;
}

bool Comparison :: isGreaterThanOrEqual(float value, float boundary){
 bool result = ((value >= boundary)?(true):(false));
 if (!result){
   cout<<"value is less than boundary"<<endl;
 }
 return result;
}

bool Comparison :: isInRange(float value, float lowerBoundary, float upperBoundary){
 return (isLessThanOrEqual(value, upperBoundary) && isGreaterThanOrEqual(value, lowerBoundary));
}

Comparison comparisonObject;

class Battery{
  public:
    const float TEMPERATURE_LOWER_BOUNDARY = 0;
    const float TEMPERATURE_UPPER_BOUNDARY = 45;
    const float SOC_LOWER_BOUNDARY = 20;
    const float SOC_LOWER_BOUNDARY_WARNING = 24;
    const float SOC_UPPER_BOUNDARY_WARNING = 76;
    const float SOC_UPPER_BOUNDARY = 80;
    const float CHARGE_RATE_BOUNDARY = 0.8;
};

class BatteryManagementSystem : public Battery{
  public:
    bool isBatteryTemperatureOk(float temperature);
    bool isBatteryStateOfChargeOk(float soc);
    void batterySocWarningLow(float soc);
    void batterySocWarningHigh(float soc);
    bool isBatteryChargeRateOk(float chargeRate);
};

bool BatteryManagementSystem :: isBatteryTemperatureOk(float temperature){
 bool result = comparisonObject.isInRange(temperature, TEMPERATURE_LOWER_BOUNDARY, TEMPERATURE_UPPER_BOUNDARY);
 if(!result) {
   cout << "Temperature "<<temperature<< " is out of range!"<<endl;
 }
 return result;
}

void BatteryManagementSystem :: batterySocWarningLow(float soc) {
 bool result = comparisonObject.isInRange(soc, SOC_LOWER_BOUNDARY, SOC_LOWER_BOUNDARY_WARNING);
 if(result) {
   switch(logLanguage){
     case English :
        cout << "Warning: Approaching discharge!"<<endl;
        break;
     case German :
        cout <<"Warnung: Naht Entladung!"<<endl;
        break;
     default:
        cout <<"Please select a language!"<<endl;
        break;
   }
 }
}

void BatteryManagementSystem :: batterySocWarningHigh(float soc) {
 bool result = comparisonObject.isInRange(soc, SOC_UPPER_BOUNDARY_WARNING, SOC_UPPER_BOUNDARY);
 if(result) {
   cout << "Warning: Approaching charge-peak!"<<endl;
 }
}

bool BatteryManagementSystem :: isBatteryStateOfChargeOk(float soc){
 bool result = comparisonObject.isInRange(soc, SOC_LOWER_BOUNDARY, SOC_UPPER_BOUNDARY);
 batterySocWarningLow(soc);
 batterySocWarningHigh(soc);
 if(!result) {
   cout << "State of Charge "<<soc<< " is out of range!"<<endl;
 }
 return result;
}

bool BatteryManagementSystem :: isBatteryChargeRateOk(float chargeRate){
  bool result = comparisonObject.isLessThanOrEqual(chargeRate, CHARGE_RATE_BOUNDARY);
  if(!result) {
    cout << "Charge Rate "<<chargeRate<< " is out of range!" <<endl;
  }
  return result;
}

int main() {
  BatteryManagementSystem bmsObject;
  Battery batteryObject;

  assert(bmsObject.isBatteryTemperatureOk(batteryObject.TEMPERATURE_LOWER_BOUNDARY - 1) == false);
  assert(bmsObject.isBatteryTemperatureOk(batteryObject.TEMPERATURE_LOWER_BOUNDARY) == true);
  assert(bmsObject.isBatteryTemperatureOk(batteryObject.TEMPERATURE_LOWER_BOUNDARY + 1) == true);
  assert(bmsObject.isBatteryTemperatureOk(batteryObject.TEMPERATURE_UPPER_BOUNDARY - 1) == true);
  assert(bmsObject.isBatteryTemperatureOk(batteryObject.TEMPERATURE_UPPER_BOUNDARY) == true);
  assert(bmsObject.isBatteryTemperatureOk(batteryObject.TEMPERATURE_UPPER_BOUNDARY + 1) == false);

  assert(bmsObject.isBatteryStateOfChargeOk(batteryObject.SOC_LOWER_BOUNDARY - 1) == false);
  assert(bmsObject.isBatteryStateOfChargeOk(batteryObject.SOC_LOWER_BOUNDARY) == true);
  assert(bmsObject.isBatteryStateOfChargeOk(batteryObject.SOC_LOWER_BOUNDARY + 1) == true);
  assert(bmsObject.isBatteryStateOfChargeOk(batteryObject.SOC_UPPER_BOUNDARY - 1) == true);
  assert(bmsObject.isBatteryStateOfChargeOk(batteryObject.SOC_UPPER_BOUNDARY) == true);
  assert(bmsObject.isBatteryStateOfChargeOk(batteryObject.SOC_UPPER_BOUNDARY + 1) == false);

  assert(bmsObject.isBatteryChargeRateOk(batteryObject.CHARGE_RATE_BOUNDARY - 1) == true);
  assert(bmsObject.isBatteryChargeRateOk(batteryObject.CHARGE_RATE_BOUNDARY) == true);
  assert(bmsObject.isBatteryChargeRateOk(batteryObject.CHARGE_RATE_BOUNDARY +1) == false);
}
