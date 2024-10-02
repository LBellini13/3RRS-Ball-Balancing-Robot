#ifndef DEGREE_MULTI_STEPPER
#define DEGREE_MULTI_STEPPER

#include <AccelStepper.h>
#include <MultiStepper.h>
#include "DegreeStepper.h"

/// @class DegreeMultiStepper
/// Class that extends the MultiStepper library to allow controlling multiple DegreeStepper motors in degrees.
class DegreeMultiStepper : public MultiStepper {
  private:
    uint8_t numSteppers = 0;
    float stepsPerDegree[MULTISTEPPER_MAX_STEPPERS];
  public:
    /// Adds a DegreeStepper to the collection.
    /// @param stepper -> a reference to a DegreeStepper instance
    void addStepper(DegreeStepper& stepper);

    /// Moves all steppers to the target positions specified in degrees.
    /// Each stepper can have its own target position.
    /// @param absoluteDegrees -> array of target positions in degrees
    void moveToDegree(long absoluteDegrees[]);
};

#endif
