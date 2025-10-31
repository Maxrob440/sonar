#include "distancereader.h"
#include <random>
#include <QDebug>
#include <chrono>
#include <iostream>
DistanceReader::DistanceReader(int handle):h(handle) {
  if (h!=0){
    lgGpioClaimOutput(h,0,TRIG,0);
    lgGpioClaimInput(h,0,ECHO);
  }

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
    lgGpioWrite(h,TRIG,1);
    std::this_thread::sleep_for(std::chrono::microseconds(10));
    lgGpioWrite(h,TRIG,0);
    while (lgGpioRead(h,ECHO)==0){}
    auto start = std::chrono::steady_clock::now();
    while(lgGpioRead(h,ECHO)==1){}

    auto end = std::chrono::steady_clock::now();
  
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

   double distance = (elapsed * 0.0343)/2;

    std::cout<<distance<<"cm\n";
    return distance;
}
