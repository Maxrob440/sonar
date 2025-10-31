#ifndef DISTANCEREADER_H
#define DISTANCEREADER_H

class DistanceReader{
public:
  virtual ~DistanceReader()=default;
  virtual double getDistance()=0;
  
};
#endif
