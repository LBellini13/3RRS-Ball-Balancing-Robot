#include <AccelStepper.h>
#include <MultiStepper.h>
#include "DegreeStepper.h"
#include "DegreeMultiStepper.h"

const uint8_t n_steppers = 2;

const int dirPin_1 = 2;
const int stepPin_1 = 3;
const int enPin_1 = 4;

const int dirPin_2 = 6;
const int stepPin_2 = 7;
const int enPin_2 = 8;
// int absolutePos = -90;
long absoluteDegreePositions[n_steppers] = {5000, 5000};

DegreeStepper degreeStepper_1(stepPin_1, dirPin_1, enPin_1);
DegreeStepper degreeStepper_2(stepPin_2, dirPin_2, enPin_2);
DegreeMultiStepper degreeMultiStepper;

// AccelStepper myStepper(AccelStepper::DRIVER, stepPin, dirPin);

void setup() {
  Serial.begin(9600);
  degreeStepper_1.disable();
  Serial.print("Driver disabled");
  Serial.println(digitalRead(enPin_1));
  degreeStepper_2.disable();

  degreeStepper_1.setCurrentPositionInDegree(0);
  degreeStepper_1.setMaxSpeed(500);
  degreeStepper_1.setSpeed(200);
  degreeStepper_1.setAcceleration(500);
  degreeStepper_1.setMicrosteppingFactor(0.5);

  Serial.print("Steps per Degree: ");
  Serial.println(degreeStepper_1.returnStepsPerDegree());
  degreeStepper_2.setCurrentPositionInDegree(0);
  degreeStepper_2.setMaxSpeed(500);
  degreeStepper_2.setSpeed(200);
  degreeStepper_2.setAcceleration(500);
  degreeStepper_2.setMicrosteppingFactor(0.5);


  degreeMultiStepper.addStepper(degreeStepper_1);
  degreeMultiStepper.addStepper(degreeStepper_2);
  // multiStepper.addStepper(degreeStepper_1);
  // multiStepper.addStepper(degreeStepper_2);

  delay(1000);

  degreeStepper_1.enable();
  Serial.print("Driver enabled");
  Serial.println(digitalRead(enPin_1));
  degreeStepper_2.enable();
  Serial.println("SETUP COMPLETE");
}

void loop() {
  // absolutePos = -absolutePos;
  // degreeStepper_1.moveToDegree(absolutePos);
  // while (degreeStepper_1.distanceToGo() != 0) {
  //   degreeStepper_1.run();
  //   Serial.println("I'M TURNING");
  // }
  // delay(2000);
  // Serial.println("TURN COMPLETE, GO BACK");
  // delay(2000);
  degreeMultiStepper.moveToDegree(absoluteDegreePositions);
  while(degreeStepper_1.distanceToGo() != 0 && degreeStepper_2.distanceToGo() != 0){
    degreeMultiStepper.run();
  }
}
