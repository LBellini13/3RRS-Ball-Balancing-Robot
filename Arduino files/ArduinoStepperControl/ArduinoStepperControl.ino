#include <AccelStepper.h>
#include <MultiStepper.h>

#include "DegreeStepper.h"

const int dirPin = 2;
const int stepPin = 4;
const int enPin = 8;
int pos = 90;

DegreeStepper degreeStepper(stepPin, dirPin, enPin);

// AccelStepper myStepper(AccelStepper::DRIVER, stepPin, dirPin);

void setup() {
  degreeStepper.disable();
  degreeStepper.setCurrentPositionInDegree(0);
  degreeStepper.setMaxSpeed(1000);
  degreeStepper.setSpeed(800)
  degreeStepper.setAcceleration(500)
  degreeStepper.enable();
}

void loop() {
  degreeStepper.moveToDegree(pos)
  // myStepper.runToPosition();
  while (degreeStepper.distanceToGo() != 0) {
   myStepper.run();
  }
  degreeStepper.currentPositionInDegree()

}
