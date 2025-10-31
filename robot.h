#ifndef ROBOT_H
#define ROBOT_H
#include <memory>
#include "distancereader.h"
#include "directionreader.h"
class Robot
{
public:
  int h;
    Robot();
    double getDistance();
    double getDirection();
  std::unique_ptr<DistanceReader> distanceReader;
    DirectionReader directionReader;
};

#endif // ROBOT_H
