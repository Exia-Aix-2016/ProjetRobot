#include "Arduino.h"

class Trajectory {

class T {
private:
  int angle;
  int t_start;
public:
  T(){
    this->t_start = millis();
  }

  int getAngle(void){
    return this->angle;
  }

  int getDelta(void){
    return millis() - this->t_start;
  }

};


private:

  T current;
  T rectify;

  void calculRectify(){
    
  }

public:

  Trajectory (){

  }

  void changeAngle(){

  }

  void changeSpeed(){

  }

};
