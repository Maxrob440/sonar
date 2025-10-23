#ifndef ROBOT_H
#define ROBOT_H
#include "distancereader.h"
#include "directionreader.h"

class Robot
{
public:
    DistanceReader distanceReader = DistanceReader();
    DirectionReader directionReader = DirectionReader();
    Robot();
    double getDistance();
    double getDirection();
};

#endif // ROBOT_H
