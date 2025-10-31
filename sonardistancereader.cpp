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
    lgGpioWrite(h,TRIG,1); // turn pin on
    std::this_thread::sleep_for(std::chrono::microseconds(10));
    lgGpioWrite(h,TRIG,0); // turn off

    while (lgGpioRead(h,ECHO)==0){} // wait until ==1
    auto start = std::chrono::steady_clock::now(); // record time
    while(lgGpioRead(h,ECHO)==1){} // wait until ==0
    auto end = std::chrono::steady_clock::now(); // record time
  
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

   double distance = (elapsed * 0.0343)/2; // distance = speed * time, /2 as there and back

    std::cout<<distance<<"cm\n";
    return distance;
}
