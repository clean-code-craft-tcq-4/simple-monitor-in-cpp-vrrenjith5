#include <iostream>
#include "comparison.h"

using namespace std;

bool Comparison :: isLessThanOrEqual(float value, float boundary){
  return ((value <= boundary)?(true):(false));
}

bool Comparison :: isLessThan(float value, float boundary){
  return ((value < boundary)?(true):(false));
}

bool Comparison :: isGreaterThan(float value, float boundary){
  return ((value > boundary)?(true):(false));
}

bool Comparison :: isGreaterThanOrEqual(float value, float boundary){
  return ((value >= boundary)?(true):(false));
}

bool Comparison :: isWithInRange(float value, float lowerBoundary, float upperBoundary){
  return (isLessThanOrEqual(value, upperBoundary) && isGreaterThanOrEqual(value, lowerBoundary));
}

