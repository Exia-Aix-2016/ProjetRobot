#include <Servo.h>
#include "Trajectory.cpp"

class Direction {
private:

  Servo myservo;

  int value;

  int pin;
  int left_max;
  int right_max;

  void attach(){
    myservo.attach(pin);
  }

  void turn(){
    myservo.write(value);
  }

public:

  Direction(int p, int l, int r /*,Trajectory trajectory*/){
    pin = p;
    left_max = l;
    right_max = r;
    attach();
  }

  void center(){
    int d = left_max < right_max ? (left_max + (right_max - left_max)/2) : (right_max + (left_max - right_max)/2);
    value = d;
    turn();
  }

  void right() {
    value = right_max;
    turn();
  }

  void left() {
    value = left_max;
    turn();
  }

  int getValue(void){
    return value;
  }

  void setValue(int d) {
    if (left_max < right_max) {
      if (d >= left_max && d <= right_max) {
        value = d;
      }
    } else if(left_max > right_max){
      if (d <= left_max && d >= right_max) {
        value = d;
      }
    }
    turn();
  }

};
