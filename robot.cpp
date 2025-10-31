#include "robot.h"
#include "distancereader.h"
#include <lgpio.h>
Robot::Robot() 
  :h(lgGpiochipOpen(0)),
  distanceReader(h),
  directionReader()
{}

double Robot::getDistance(){
    return distanceReader.getDistance();
}
double Robot::getDirection(){
    // Returns in radians
    return directionReader.getRadiansDirection();
}
