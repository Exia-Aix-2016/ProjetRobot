#include "Arduino.h"

#include "controllers/Race.cpp"

const int SERVO_PIN = 3;
const int SERVO_LMAX =  0;
const int SERVO_RMAX = 90;

const int RELAY1_PIN = 5;
const int RELAY2_PIN = 4;

const int TRIGGER_PIN = 8;
const int ECHO_PIN = 9;

Race race;

void setup() {
  Serial.begin(9600);
}

void loop() {

  Serial.println("Starting Race");
  race.start();
  Serial.println("Race ended");

}
