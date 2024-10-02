#include "DegreeMultiStepper.h"
#include "DegreeStepper.h"

void DegreeMultiStepper::addStepper(DegreeStepper& stepper) {
    // Add the stepper to the underlying MultiStepper collection
    MultiStepper::addStepper(stepper);
    stepsPerDegree[numSteppers++] = stepper.returnStepsPerDegree();
}

void DegreeMultiStepper::moveToDegree(long absoluteDegrees[]) {
    long absoluteSteps[numSteppers];
    for (uint8_t i = 0; i < numSteppers; i++)
    {
        absoluteSteps[i] = absoluteDegrees[i] * stepsPerDegree[i];
    }
    // Use the underlying MultiStepper library to move to the target steps
    MultiStepper::moveTo(absoluteSteps);
}

