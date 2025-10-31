#ifndef RANDOMDISTANCEREADER_H
#define RANDOMDISTANCEREADER_H
#include "distancereader.h"
class RandomDistanceReader : public DistanceReader{
public:
  int maxRange;
  int minRange;
  
  RandomDistanceReader(int maxRange =200,
                       int minRange =2);
  double getDistance();
};
#endif
