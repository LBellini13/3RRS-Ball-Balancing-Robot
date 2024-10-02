#include "DegreeStepper.h"
#include <AccelStepper.h>

DegreeStepper::DegreeStepper(uint8_t stepPin, uint8_t directionPin, uint8_t enablePin)
: AccelStepper(AccelStepper::DRIVER, stepPin, directionPin){
    enPin = enablePin;
    stepsPerDegree = 200.0 / 360.0;
}

void DegreeStepper::enable(){
    pinMode(enPin, OUTPUT);
    digitalWrite(enPin, LOW);
}

void DegreeStepper::disable(){
    pinMode(enPin, OUTPUT);
    digitalWrite(enPin, HIGH);
}

void DegreeStepper::setMicrosteppingFactor(float microsteppingFactor=1){
    stepsPerDegree = stepsPerDegree / microsteppingFactor;
}

float DegreeStepper::returnCurrentPositionInDegree(){
    return currentPosition() / stepsPerDegree;
}

void DegreeStepper::setCurrentPositionInDegree(float positionInDegree){
    setCurrentPosition((long) positionInDegree * stepsPerDegree);
}

void DegreeStepper::moveToDegree(float absoluteDegree){
    moveTo((long) absoluteDegree * stepsPerDegree);
}

void DegreeStepper::moveDegree(float relativeDegree){
    move((long) relativeDegree * stepsPerDegree);
}

float DegreeStepper::returnStepsPerDegree(){
    return stepsPerDegree;
}