#ifndef DEGREE_STEPPER
#define DEGREE_STEPPER

#include <AccelStepper.h>

class DegreeStepper : public AccelStepper{
  private:
    uint8_t enPin;
    float stepsPerDegree;

  public:
    DegreeStepper(uint8_t stepPin, uint8_t dirPin, uint8_t enPin, uint8_t microsteppinFactor);

    void enable();

    void disable();
    
    void setMicrosteppingFactor(uint8_t microsteppingFactor);

    float currentPositionInDegree();

    void setCurrentPositionInDegree(float positionInDegree);

    void moveToDegree(float absoluteDegree);

    void moveDegree(float relativeDegree);
};

#endif