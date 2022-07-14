#include <iostream>
#include "comparison.h"

using namespace std;

bool Comparison :: isLessThanOrEqual(float value, float boundary){
  bool result = ((value <= boundary)?(true):(false));
  return result;
}

bool Comparison :: isLessThan(float value, float boundary){
  bool result = ((value < boundary)?(true):(false));
  return result;
}

bool Comparison :: isGreaterThan(float value, float boundary){
  bool result = ((value > boundary)?(true):(false));
  return result;
}

bool Comparison :: isGreaterThanOrEqual(float value, float boundary){
  bool result = ((value >= boundary)?(true):(false));
  return result;
}

bool Comparison :: isWithInRange(float value, float lowerBoundary, float upperBoundary){
  return (isLessThanOrEqual(value, upperBoundary) && isGreaterThanOrEqual(value, lowerBoundary));
}

