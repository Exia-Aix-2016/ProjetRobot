#include "Arduino.h"

#include "Direction.cpp"

const int SERVO_PIN = 3;
const int SERVO_LMAX =  0;
const int SERVO_RMAX = 90;

Direction* direction;

void setup() {
  direction = new Direction(SERVO_PIN, SERVO_LMAX, SERVO_RMAX);
  Serial.begin(9600);
}

void loop() {
  direction->center();
  Serial.println(direction->getValue());
  /*delay(1000);
  direction->right();
  delay(1000);
  direction->left();
  delay(1000);*/
}
