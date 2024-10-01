#include <AccelStepper.h>
#include <MultiStepper.h>

#include "DegreeStepper.h"

const int dirPin_1 = 2;
const int stepPin_1 = 3;
const int enPin_1 = 4;

const int dirPin_2 = 5;
const int stepPin_2 = 6;
const int enPin_2 = 7;
int pos = 90;

DegreeStepper degreeStepper_1(stepPin_1, dirPin_1, enPin_1);
DegreeStepper degreeStepper_2(stepPin_2, dirPin_2, enPin_2);
MultiStepper multiStepper;

// AccelStepper myStepper(AccelStepper::DRIVER, stepPin, dirPin);

void setup() {
  degreeStepper_1.disable();
  degreeStepper_2.disable();

  degreeStepper_1.setCurrentPositionInDegree(0);
  degreeStepper_1.setMaxSpeed(1000);
  degreeStepper_1.setSpeed(800);
  degreeStepper_1.setAcceleration(500);
  degreeStepper_2.setCurrentPositionInDegree(0);
  degreeStepper_2.setMaxSpeed(1000);
  degreeStepper_2.setSpeed(800);
  degreeStepper_2.setAcceleration(500);

  multiStepper.addStepper(degreeStepper_1);
  multiStepper.addStepper(degreeStepper_2);

  degreeStepper_1.enable();
  degreeStepper_2.enable();
}

void loop() {
  degreeStepper_1.moveToDegree(pos);
  // myStepper.runToPosition();
  while (degreeStepper_1.distanceToGo() != 0) {
   degreeStepper_1.run();
  }
}
