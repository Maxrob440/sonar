#ifndef SONARDISTANCEREADER_H
#define SONARDISTANCEREADER_H
#include<thread>
#include <lgpio.h>
#include "distancereader.h"
class SonarDistanceReader : public DistanceReader
{
public:
    int TRIG = 23;
    int ECHO = 24;
    int h;
    SonarDistanceReader(int h);
    double getDistance();
};

#endif // DISTANCEREADER_H
