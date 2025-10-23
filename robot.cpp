#include "robot.h"
#include "distancereader.h"

Robot::Robot() {}

double Robot::getDistance(){
    return distanceReader.getDistance();
}
double Robot::getDirection(){
    // Returns in radians
    return directionReader.getRadiansDirection();
}
