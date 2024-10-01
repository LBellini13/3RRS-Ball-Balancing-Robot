#include "DegreeStepper.h"
#include <AccelStepper.h>

DegreeStepper::DegreeStepper(uint8_t interface, uint8_t stepPin, uint8_t dirPin, uint8_t enPin, float microsteppingFactor)
: AccelStepper(AccelStepper::DRIVER, stepPin, dirPin){
    pinMode(enPin, OUTPUT);
    digitalWrite(enPin, HIGH);
    enPin = enPin
    stepsPerDegree = 200 /360;
    digitaWrite(enPin, LOW);
}

void DegreeStepper::enable(){
    pinMode(enPin, OUTPUT);
    digitslWrite(enPin, LOW);
}

void DegreeStepper::disable(){
    pinMode(enPin, OUTPUT);
    digitslWrite(enPin, HIGH);
}


void DegreeStepper::setMIcrosteppingFactor(uint8_t microsteppingFactor){
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


// #include "degreeStepper.h"

// // Costruttore
// DegreeStepper::DegreeStepper(uint8_t interfaceType, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, bool enable) 
// : AccelStepper(interfaceType, pin1, pin2, pin3, pin4, enable) {
//     stepsPerDegree = 200.0 / 360.0;  // Default: 200 passi per rivoluzione (1.8 gradi per passo)
// }

// // Imposta il numero di passi per rivoluzione
// void DegreeStepper::setStepsPerRevolution(float stepsPerRevolution) {
//     stepsPerDegree = stepsPerRevolution / 360.0;
// }

// // Muovi il motore a una certa posizione in gradi
// void DegreeStepper::moveToDegree(float degreeTarget) {
//     // Converti i gradi in passi
//     long stepTarget = (long)(degreeTarget * stepsPerDegree);
//     moveTo(stepTarget);  // Usa il metodo moveTo della classe AccelStepper
// }

// // Restituisci la posizione corrente in gradi
// float DegreeStepper::currentPositionInDegrees() {
//     // Converti la posizione corrente in passi a gradi
//     return currentPosition() / stepsPerDegree;
// }

// // Imposta la posizione corrente in gradi
// void DegreeStepper::setCurrentPositionInDegrees(float degreePosition) {
//     // Converti i gradi in passi e imposta la posizione corrente
//     setCurrentPosition((long)(degreePosition * stepsPerDegree));
// }
