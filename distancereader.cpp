#include "distancereader.h"
#include <random>
#include <QDebug>

DistanceReader::DistanceReader() {
}

double DistanceReader:: getRandomDistance(){

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(10,100);
    if (dist(rng)<15){

        int distance = dist(rng);
        return distance;
    }
    else{
        return 100.0;
    }

}

double DistanceReader :: getDistance(){
    double timeTaken = 10; //Standard distance before setting up Pi
    double distance = timeTaken * speedOfSoundInAir;
    return distance;
}
