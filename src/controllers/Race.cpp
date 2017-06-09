#include "Controller.cpp"

#include "Arduino.h"

class Race: public Controller{
private:

public:
  typedef Controller super;

  Race(void){
    super();
  }

  void start(){
    delay(5000);
    direction->center();
    propulsion->forward();
    while (ultrasonic->ping() > 8);
    propulsion->stop();
  }
};
