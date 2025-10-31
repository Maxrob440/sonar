#ifndef DISTANCEREADER_H
#define DISTANCEREADER_H
#include<thread>
#include <lgpio.h>
class DistanceReader
{
public:
    int TRIG = 23;
    int ECHO = 24;
    int h;
    DistanceReader(int h);
    double getDistance();
    double getRandomDistance();
};

#endif // DISTANCEREADER_H
