#include "Arduino.h"

#include "actuators/Direction.cpp"
#include "actuators/Propulsion.cpp"

const int SERVO_PIN = 3;
const int SERVO_LMAX =  0;
const int SERVO_RMAX = 90;

const int RELAY1_PIN = 5;
const int RELAY2_PIN = 4;

//Trajectory trajectory;
Direction* direction;
Propulsion* propulsion;


void setup() {
  //direction = new Direction(SERVO_PIN, SERVO_LMAX, SERVO_RMAX, trajectory);
  propulsion = new Propulsion(RELAY1_PIN, RELAY2_PIN);
}

void loop() {
  propulsion->backward();
  delay(5000);
  propulsion->forward();
  delay(5000);
  propulsion->stop();
  delay(5000);

  //direction->center();
  //Serial.println(direction->getValue());
  /*delay(1000);
  direction->right();
  delay(1000);
  direction->left();
  delay(1000);*/
}
