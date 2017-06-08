#include "Arduino.h"

enum Sens {
  FORWARD,
  BACKWARD
};


class Propulsion {
private:

  Sens sens;
  bool state;

  int pin_state;
  int pin_sens;

  void apply(){
    switch (sens) {
      case FORWARD:
        digitalWrite(pin_sens, HIGH);
        break;
      case BACKWARD:
        digitalWrite(pin_sens, LOW);
        break;
    }

    switch (state) {
      case true:
        digitalWrite(pin_state, HIGH);
        break;
      case false:
        digitalWrite(pin_state, LOW);
        break;
    }

  }

public:

  Propulsion (int r1, int r2){
    state = false;
    sens = Sens::FORWARD;

    pin_sens = r1;
    pin_state = r2;

    pinMode(pin_state, OUTPUT);
    pinMode(pin_sens, OUTPUT);
  }

  void forward(void){
    sens = Sens::FORWARD;
    state = true;
    apply();
  }

  void backward(void){
    sens = Sens::BACKWARD;
    state = true;
    apply();
  }

  void stop(void){
    state = false;
    apply();
  }
};
