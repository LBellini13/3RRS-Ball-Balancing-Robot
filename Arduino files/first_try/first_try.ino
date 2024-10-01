#include <AccelStepper.h>
#include <MultiStepper.h>

const int dirPin = 2;
const int stepPin = 4;
int pos = 400;

AccelStepper myStepper(AccelStepper::DRIVER, stepPin, dirPin);

void setup() {
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  myStepper.setCurrentPosition(0);
  myStepper.setMaxSpeed(1000);
  myStepper.setSpeed(300);
  myStepper.setAcceleration(500);
  digitalWrite(8, LOW);
}

void loop() {
  pos = -pos;
  myStepper.move(pos);
  // myStepper.runToPosition();
  while (myStepper.distanceToGo() != 0) {
   myStepper.run();
  }

}
