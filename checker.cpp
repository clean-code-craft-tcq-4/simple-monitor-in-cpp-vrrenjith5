#include <assert.h>
#include <iostream>

typedef enum Language{
  English = 0,
  German,
};

static int logLanguage = English;

using namespace     std;
const float TEMPERATURE_LOWER_BOUNDARY = 0;
const float TEMPERATURE_UPPER_BOUNDARY = 45;
const float SOC_LOWER_BOUNDARY = 20;
const float SOC_LOWER_BOUNDARY_WARNING = 24;
const float SOC_UPPER_BOUNDARY_WARNING = 76;
const float SOC_UPPER_BOUNDARY = 80;
const float CHARGE_RATE_BOUNDARY = 0.8;

class ElectricVehicle{
  public:
    bool isLessThanOrEqual(float value, float boundary);
    bool isGreaterThanOrEqual(float value, float boundary);
    bool isInRange(float value, float lowerBoundary, float upperBoundary);
};

class Battery: public ElectricVehicle {
  public:
    bool isBatteryTemperatureOk(float temperature);
    bool isBatteryStateOfChargeOk(float soc);
    void batterySocWarningLow(float soc);
    void batterySocWarningHigh(float soc);
    bool isBatteryChargeRateOk(float chargeRate);
};

bool ElectricVehicle :: isLessThanOrEqual(float value, float boundary){
 bool result = ((value <= boundary)?(true):(false));
 if (!result){
   cout<<"value is greater than boundary"<<endl;
 }
 return result;
}

bool ElectricVehicle :: isGreaterThanOrEqual(float value, float boundary){
 bool result = ((value >= boundary)?(true):(false));
 if (!result){
   cout<<"value is less than boundary"<<endl;
 }
 return result;
}

bool ElectricVehicle :: isInRange(float value, float lowerBoundary, float upperBoundary){
 return (isLessThanOrEqual(value, upperBoundary) && isGreaterThanOrEqual(value, lowerBoundary));
}

bool Battery :: isBatteryTemperatureOk(float temperature){
 bool result = isInRange(temperature, TEMPERATURE_LOWER_BOUNDARY, TEMPERATURE_UPPER_BOUNDARY);
 if(!result) {
   cout << "Temperature "<<temperature<< " is out of range!"<<endl;
 }
 return result;
}

void Battery :: batterySocWarningLow(float soc) {
 bool result = isInRange(soc, SOC_LOWER_BOUNDARY, SOC_LOWER_BOUNDARY_WARNING);
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

void Battery :: batterySocWarningHigh(float soc) {
 bool result = isInRange(soc, SOC_UPPER_BOUNDARY_WARNING, SOC_UPPER_BOUNDARY);
 if(result) {
   cout << "Warning: Approaching charge-peak!"<<endl;
 }
}

bool Battery :: isBatteryStateOfChargeOk(float soc){
 bool result = isInRange(soc, SOC_LOWER_BOUNDARY, SOC_UPPER_BOUNDARY);
 batterySocWarningLow(soc);
 batterySocWarningHigh(soc);
 if(!result) {
   cout << "State of Charge "<<soc<< " is out of range!"<<endl;
 }
 return result;
}

bool Battery :: isBatteryChargeRateOk(float chargeRate){
  bool result = isLessThanOrEqual(chargeRate, CHARGE_RATE_BOUNDARY);
  if(!result) {
    cout << "Charge Rate "<<chargeRate<< " is out of range!" <<endl;
  }
  return result;
}

int main() {
  Battery BatteryObject;
  assert(BatteryObject.isBatteryTemperatureOk(TEMPERATURE_LOWER_BOUNDARY - 1) == false);
  assert(BatteryObject.isBatteryTemperatureOk(TEMPERATURE_LOWER_BOUNDARY) == true);
  assert(BatteryObject.isBatteryTemperatureOk(TEMPERATURE_LOWER_BOUNDARY + 1) == true);
  assert(BatteryObject.isBatteryTemperatureOk(TEMPERATURE_UPPER_BOUNDARY - 1) == true);
  assert(BatteryObject.isBatteryTemperatureOk(TEMPERATURE_UPPER_BOUNDARY) == true);
  assert(BatteryObject.isBatteryTemperatureOk(TEMPERATURE_UPPER_BOUNDARY + 1) == false);

  assert(BatteryObject.isBatteryStateOfChargeOk(SOC_LOWER_BOUNDARY - 1) == false);
  assert(BatteryObject.isBatteryStateOfChargeOk(SOC_LOWER_BOUNDARY) == true);
  assert(BatteryObject.isBatteryStateOfChargeOk(SOC_LOWER_BOUNDARY + 1) == true);
  assert(BatteryObject.isBatteryStateOfChargeOk(SOC_UPPER_BOUNDARY - 1) == true);
  assert(BatteryObject.isBatteryStateOfChargeOk(SOC_UPPER_BOUNDARY) == true);
  assert(BatteryObject.isBatteryStateOfChargeOk(SOC_UPPER_BOUNDARY + 1) == false);

  assert(BatteryObject.isBatteryChargeRateOk(CHARGE_RATE_BOUNDARY - 1) == true);
  assert(BatteryObject.isBatteryChargeRateOk(CHARGE_RATE_BOUNDARY) == true);
  assert(BatteryObject.isBatteryChargeRateOk(CHARGE_RATE_BOUNDARY +1) == false);
}
