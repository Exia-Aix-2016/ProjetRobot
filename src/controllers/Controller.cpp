#include "sensors/UltraSonic.cpp"
#include "actuators/Propulsion.cpp"
#include "actuators/Direction.cpp"


class Controller {
protected:

  const int SERVO_PIN = 3;
  const int SERVO_LMAX =  0;
  const int SERVO_RMAX = 90;

  const int RELAY1_PIN = 5;
  const int RELAY2_PIN = 4;

  const int TRIGGER_PIN = 8;
  const int ECHO_PIN = 9;

  Direction* direction;
  Propulsion* propulsion;
  UltraSonic* ultrasonic;

public:
  Controller(){
    direction = new Direction(SERVO_PIN, SERVO_LMAX, SERVO_RMAX);
    propulsion = new Propulsion(RELAY1_PIN, RELAY2_PIN);
    ultrasonic = new UltraSonic(TRIGGER_PIN, ECHO_PIN);
  }
};
