#include "directionreader.h"
#include <cmath>
#include <random>

DirectionReader::DirectionReader() {
    direction = 90.0;
}

double DirectionReader::getDirection(){
    return direction;
}

double DirectionReader::getRadiansDirection(){
    return direction*(3.1415926535897932/180);
}

void DirectionReader::addDirection(double degrees){
    direction= std::fmod(direction+degrees,360);
}
