#include "robot.h"
#include "sonardistancereader.h"
#include "randomdistancereader.h"
#include <lgpio.h>
#include <iostream>
Robot::Robot() 
  :h(lgGpiochipOpen(0)),
  directionReader(h)
{
  if (h<0){
    // Randomised for testing on computer
    distanceReader = std::make_unique<RandomDistanceReader>(10,200);
  }
  else{
    // real sensor conection
    distanceReader = std::make_unique<SonarDistanceReader>(h);
  }
}

double Robot::getDistance(){
  // returns in cm
    return distanceReader->getDistance();
}
double Robot::getDirection(){
    // Returns in radians
    return directionReader.getRadiansDirection();
}
