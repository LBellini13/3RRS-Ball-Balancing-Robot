#include "DegreeStepper.h"
#include <AccelStepper.h>

DegreeStepper::DegreeStepper(uint8_t stepPin, uint8_t dirPin, uint8_t enPin)
: AccelStepper(AccelStepper::DRIVER, stepPin, dirPin){
    enPin = enPin;
    stepsPerDegree = 200 /360;
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

float DegreeStepper::currentPositionInDegree(){
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

long DegreeStepper::degreesToSteps(float degrees) {
    return (long)(degrees * stepsPerDegree);
}