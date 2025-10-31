#include "sonardistancereader.h"
#include <QDebug>
#include <chrono>
#include <iostream>
SonarDistanceReader::SonarDistanceReader(int handle):h(handle) {
  if (h!=0){
    lgGpioClaimOutput(h,0,TRIG,0);
    lgGpioClaimInput(h,0,ECHO);
  }

}



double SonarDistanceReader :: getDistance(){
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
