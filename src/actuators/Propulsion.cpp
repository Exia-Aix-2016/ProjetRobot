#include "Arduino.h"

enum Sens {
  FORWARD,
  BACKWARD
};


class Propulsion {
private:

  int speed;
  Sens sens;

  int pin_transistor;
  int pin_relay;

  void applySens(){
    switch (sens) {
      case FORWARD:
        digitalWrite(pin_relay, LOW);
        break;
      case BACKWARD:
        digitalWrite(pin_relay, HIGH);
        break;
    }
  }

  void applySpeed(void){
    analogWrite(pin_transistor, speed);
  }

public:

  Propulsion (int t, int r){
    speed = 0;
    sens = Sens::FORWARD;

    pin_transistor = t;
    pin_relay = r;

    pinMode(pin_transistor, OUTPUT);
    pinMode(pin_relay, OUTPUT);
  }

  void forward(void){
    sens = Sens::FORWARD;
    applySens();
  }

  void backward(void){
    sens = Sens::BACKWARD;
    applySens();
  }

  void setSpeed(int s){
    speed = map(s, 0, 100, 0, 255);
    applySpeed();
  }
};
