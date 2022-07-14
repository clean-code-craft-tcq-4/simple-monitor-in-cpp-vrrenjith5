#ifndef __COMPARISON_H_
#define __COMPARISON_H_

class Comparison{
  public:
    bool isLessThanOrEqual(float value, float boundary);
    bool isGreaterThanOrEqual(float value, float boundary);
    bool isLessThan(float value, float boundary);
    bool isGreaterThan(float value, float boundary);
    bool isWithInRange(float value, float lowerBoundary, float upperBoundary);
};

#endif /*__COMPARISON_H_*/
