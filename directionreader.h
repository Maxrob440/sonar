#ifndef DIRECTIONREADER_H
#define DIRECTIONREADER_H
#include <lgpio.h>

class DirectionReader
{
public:
    int PIN;
    int FREQ = 50;
    double direction;
    int h;
    DirectionReader(int h);
    double getDirection();
    double getRadiansDirection();
    void setDirection(double degrees);
    void addDirection(double degrees);
    int angleToPulse(double angDeg, int minUs,int maxUs);
    void moveDirection(double angDeg);
};

#endif // DIRECTIONREADER_H
