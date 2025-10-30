#ifndef DISTANCEREADER_H
#define DISTANCEREADER_H

class DistanceReader
{
public:
    double speedOfSoundInAir;
    double distance;
    DistanceReader();
    double getDistance();
    double getRandomDistance();
};

#endif // DISTANCEREADER_H
