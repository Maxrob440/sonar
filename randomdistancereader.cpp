#include "randomdistancereader.h"

#include <random>
RandomDistanceReader::RandomDistanceReader(int minV, int maxV){
  minRange=minV;
  maxRange=maxV;

}
double RandomDistanceReader:: getDistance(){

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(minRange,maxRange);
    int distance = dist(rng);
    return distance;
}
