#include "DegreeStepper.h"
#include <AccelStepper.h>

DegreeStepper::DegreeStepper(uint8_t interface, uint8_t stepPin, uint8_t dirPin, uint8_t enPin)
: AccelStepper(AccelStepper::DRIVER, stepPin, dirPin){
    enPin = enPin
    stepsPerDegree = 200 /360;
}

void DegreeStepper::enable(){
    pinMode(enPin, OUTPUT);
    digitslWrite(enPin, LOW);
}

void DegreeStepper::disable(){
    pinMode(enPin, OUTPUT);
    digitslWrite(enPin, HIGH);
}


void DegreeStepper::setMIcrosteppingFactor(float microsteppingFactor=1){
    stepsPerDegree = stepsPerDegree / microsteppingfactor;
}

float DegreeStepper::currentPositionInDegree(){
    return currentPosition() / stepsPerDegree;
}

void DegreeStepper::setCurrentPOsitionINDegree(float positionInDegree){
    setCurrentPosition((long) positionINDegree * stepsPerDegree)
}

void DegreeStepper::moveToDegree(float absoluteDegree){
    moveTo((long) absoluteDegree * stepsPerDegree)
}

void DegreeStepper::moveDegree(float relativeDegree){
    move((long) relativeDegree * stepsPerDegree)
}