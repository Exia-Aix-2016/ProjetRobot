#include "Arduino.h"

enum Sens {
  FORWARD,
  BACKWARD
};


class Propultion {
private:

  int speed;
  Sens sens;

  int pin_f1;
  int pin_f2;
  int pin_b1;
  int pin_b2;
  int pin_relay;

  void applySens(){
    switch (sens) {
      case FORWARD:
        digitalWrite(pin_f1, HIGH);
        digitalWrite(pin_f2, HIGH);
        digitalWrite(pin_b1, LOW);
        digitalWrite(pin_b1, LOW);
        break;
      case BACKWARD:
        digitalWrite(pin_f1, LOW);
        digitalWrite(pin_f2, LOW);
        digitalWrite(pin_b1, HIGH);
        digitalWrite(pin_b1, HIGH);
        break;
    }
  }

  void applySpeed(void){
    analogWrite(pin_relay, speed);
  }

public:

  Propultion (int f1, int f2, int b1, int b2, int r){
    speed = 0;
    sens = Sens::FORWARD;

    pin_f1 = f1;
    pin_f2 = f2;
    pin_b1 = b1;
    pin_b2 = b2;
    pin_relay = r;
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
