#include "Arduino.h"

class UltraSonic {
private:
  int pinTrig;
  int pinEcho;

public:
  UltraSonic (int pt, int pe){
    pinTrig = pt;
    pinEcho = pe;

    pinMode(pinTrig, OUTPUT);
    pinMode(pinEcho, INPUT);

    digitalWrite(pinTrig, LOW);
    digitalWrite(pinEcho, HIGH);
  }

  int ping(void){
    digitalWrite(pinTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrig, HIGH);
    delayMicroseconds(5);
    digitalWrite(pinTrig, LOW);

    int echo = pulseIn(pinEcho, HIGH);

    return echo/58.138;
  }
};
