#include "distancereader.h"
#include <random>
#include <qDebug>

DistanceReader::DistanceReader() {
}

double DistanceReader:: getDistance(){

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(10,100);
    if (dist(rng)<40){

        int distance = dist(rng);
        return distance;
    }
    else{
        return 100.0;
    }

}
