#include "directionreader.h"
#include <cmath>
#include <random>
#include <chrono>
#include <thread>
#include <iostream>


DirectionReader::DirectionReader(int handle):h(handle) {
  lgGpioClaimOutput(h,0,PIN,0);
}

double DirectionReader::getDirection(){
    // last orientation of the servo in degrees
    return direction;
}

double DirectionReader::getRadiansDirection(){
    //Last orientation of the servo in radians
    return direction*(3.1415926535897932/180);
}

int DirectionReader::angleToPulse(double angleDeg,
                   int minUs=1000,
                   int maxUs=2000){
    if (angleDeg<-90) angleDeg=-90; //stops from hitting end
    if (angleDeg>90) angleDeg=90; // stops hitting the end the other way

    double t = (angleDeg +90.0)/180.0; // normalises an angle to between 0-1
    return static_cast<int>(minUs+t*(maxUs-minUs)); // converts to int and returns as a value between minUs and maxUs
  }

void DirectionReader::setDirection(double angleDeg){
  // Code to move the servo
  // PIN is gpio 17 which is pin 11 on the pi
  if (h<0){return void();} // allows for testing on PC without rpi
  lgTxServo(h,PIN,angleToPulse(angleDeg),FREQ,0,0);
}

void DirectionReader::moveDirection(double angleDeg){
  // adjusts the current angle by the angleDeg
  if (direction>89 and directionMove==1){directionMove=-1;} // if moving up and angle is 90* move back down
  else if (direction <-89 and directionMove==-1){directionMove =1;} // if moving down and angle is -90 start moving up
    direction=direction + angleDeg*directionMove;
    setDirection(direction);
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

