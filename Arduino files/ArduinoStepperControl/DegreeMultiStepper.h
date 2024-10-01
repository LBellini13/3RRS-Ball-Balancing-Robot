#ifndef DEGREE_MULTI_STEPPER
#define DEGREE_MULTI_STEPPER

#include <AccelStepper.h>
#include <MultiStepper.h>
#include "DegreeStepper.h"

/// @class DegreeMultiStepper
/// Class that extends the MultiStepper library to allow controlling multiple DegreeStepper motors in degrees.
class DegreeMultiStepper : public MultiStepper {
  public:
    /// Adds a DegreeStepper to the collection.
    /// @param stepper -> a reference to a DegreeStepper instance
    void addStepper(DegreeStepper& stepper);

    /// Moves all steppers to the target positions specified in degrees.
    /// Each stepper can have its own target position.
    /// @param targetDegrees -> array of target positions in degrees
    /// @param numSteppers -> the number of steppers being controlled
    void moveToDegree(float targetDegrees[], uint8_t numSteppers);

    /// Runs all steppers until they reach their target positions.
    /// This is non-blocking; you need to call this method repeatedly in your loop.
    /// Returns true if all steppers have reached their target positions.
    bool run();
};

#endif
