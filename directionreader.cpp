#include "directionreader.h"
#include <cmath>
#include <random>

DirectionReader::DirectionReader(int handle):h(handle) {
  lgGpioClaimOutput(h,0,PIN,0);
}

double DirectionReader::getDirection(){
    return direction;
}

double DirectionReader::getRadiansDirection(){
    return direction*(3.1415926535897932/180);
}

int DirectionReader::angleToPulse(double angleDeg,
                   int minUs=1000,
                   int maxUs=2000){
    if (angleDeg<-90) angleDeg=-90;
    if (angleDeg>90) angleDeg=90;
    double t = (angleDeg +90.0)/180.0;
    return static_cast<int>(minUs+t*(maxUs-minUs));
  }
void DirectionReader::setDirection(double angleDeg){
  lgTxServo(h,PIN,angleToPulse(angleDeg),FREQ,0,0);
}
void DirectionReader::moveDirection(double angleDeg){
  if (direction>89 && direction == 1 ){
    direction = -1;
  }
  else if (direction < -89 and direction == -1){
    direction =1;
  }
    direction+=angleDeg;
}

