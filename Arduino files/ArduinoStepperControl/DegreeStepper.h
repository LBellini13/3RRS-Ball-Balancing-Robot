#ifndef DEGREE_STEPPER
#define DEGREE_STEPPER

#include <AccelStepper.h>

/// @class DegreeStepper\n
/// Class based on AccelStepper library allowing to control a stepper motor using degrees rather than steps.
class DegreeStepper : public AccelStepper{
  private:
    uint8_t enPin;
    float stepsPerDegree;

  public:
    /// StepperDegree constructor (based on TMC2208)
    /// @param stepPin -> driver step pin
    /// @param dirPin -> drive direction pin
    /// @param enPin -> driver enable pin
    DegreeStepper(uint8_t stepPin, uint8_t dirPin, uint8_t enPin);

    /// Driver enable (based on TMC2208) -> set enPin = LOW
    void enable();

    /// Driver disable (based on TMC2208) -> set enPin = HIGH
    void disable();
    
    /// Microstepping factor is set (based on TMC2208) -> possible values are 1/2, 1/4, 1/8, 1/16
    void setMicrosteppingFactor(float microsteppingFactor);

    /// Return the current motor position in degrees. Positive is clockwise from the 0 position.
    float currentPositionInDegree();

    /// Sets the current position of the motor equal the specified one. Useful
    /// for setting a zero position on a stepper after an initial hardware
    /// positioning move.
    /// Has the side effect of setting the current motor speed to 0.
    /// @param positionInDegree -> position in degrees of wherever the motor
    /// happens to be right now.
    void setCurrentPositionInDegree(float positionInDegree);

    /// Sets the new absolute target position of the stepper motor in degrees
    /// @param absoluteDegree -> new absolute target position in degrees
    void moveToDegree(float absoluteDegree);

    /// Sets the new relative target position of the stepper motor in degrees
    /// @param relativeDegree -> new relative target position in degrees
    void moveDegree(float relativeDegree);
};

#endif