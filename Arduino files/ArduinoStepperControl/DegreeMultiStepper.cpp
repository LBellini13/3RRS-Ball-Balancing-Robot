#include "DegreeMultiStepper.h"
#include "DegreeStepper.h"

void DegreeMultiStepper::addStepper(DegreeStepper& stepper) {
    // Add the stepper to the underlying MultiStepper collection
    MultiStepper::addStepper(stepper);
}

void DegreeMultiStepper::moveToDegree(float targetDegrees[], uint8_t numSteppers) {
    // Create an array for the target steps based on the degree positions
    long targetSteps[numSteppers];
    
    // Loop through each stepper and convert the target degree to steps
    for (uint8_t i = 0; i < numSteppers; i++) {
        DegreeStepper* stepper = (DegreeStepper*)_steppers[i];
        targetSteps[i] = stepper->degreesToSteps(targetDegrees[i]);  // Convert degree to steps
    }

    // Use the underlying MultiStepper library to move to the target steps
    MultiStepper::moveTo(targetSteps);
}

bool DegreeMultiStepper::run() {
    return MultiStepper::run();
}
