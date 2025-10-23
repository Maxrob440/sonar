#ifndef DIRECTIONREADER_H
#define DIRECTIONREADER_H

class DirectionReader
{
public:
    DirectionReader();
    double direction;
    double getDirection();
    double getRadiansDirection();
    void addDirection(double degrees);
};

#endif // DIRECTIONREADER_H
