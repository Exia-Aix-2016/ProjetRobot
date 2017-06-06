#include "Arduino.h"

#include "direction.cpp"

Direction* direction;

void setup() {
  direction = new Direction(3);
}

void loop() {
  direction->center();
  /*delay(1000);
  direction->right();
  delay(1000);
  direction->left();
  delay(1000);*/
}
