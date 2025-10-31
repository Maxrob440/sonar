#include "robot.h"
#include "sonardistancereader.h"
#include "randomdistancereader.h"
#include <lgpio.h>
#include <iostream>
Robot::Robot() 
  :h(lgGpiochipOpen(0)),
  // sonarDistanceReader(h),
  directionReader(h)
{
  std::cout<<h;
  if (h!=1){
    std::cout<<"random chosen\n";
    distanceReader = std::make_unique<RandomDistanceReader>(10,200);
  }
  else{
    std::cout<<"not random\n";
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
