#ifndef DIRECTIONREADER_H
#define DIRECTIONREADER_H

class DirectionReader
{
public:
    int PIN = 17;
    int FREQ = 50;
    double direction = -90;
    int h;
    double directionMove = 1;
    DirectionReader(int h);
    double getDirection();
    double getRadiansDirection();
    void setDirection(double degrees);
    void addDirection(double degrees);
    int angleToPulse(double angDeg, int minUs,int maxUs);
    void moveDirection(double angDeg);
};

#endif // DIRECTIONREADER_H
