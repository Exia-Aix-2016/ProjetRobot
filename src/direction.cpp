#include <Servo.h>

class Direction {
private:

  Servo myservo;
  int value;
  int pin;

  void attach(){
    myservo.attach(pin);
  }

  void turn(){
    myservo.write(value);
  }

public:

  Direction(int p){
    pin = p;
    attach();
  }

  void center(){
    value = 45;
    turn();
  }

  void right() {
    value = 90;
    turn();
  }

  void left() {
    value = 0;
    turn();
  }
  
};
