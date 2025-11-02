# Sonar
Sonar is a C++/Qt-based embedded project that scans the environment using a servo-mounted ultrasonic sensor and visualises distance data in real time.
It’s designed to run on a Raspberry Pi with the HC-SR04 distance sensor and SG90 servo motor, using the lgpio library for GPIO control.

### Hardware
- Raspberry Pi (any model with GPIO)
- HC-SR04 ultrasonic sensor
- SG90 servo motor
- Breadboard, jumper wires, and 5 V power source

### Software
- CMake ≥ 3.16
- Qt6 (qt6-base-dev, qt6-tools-dev)
- lgpio (liblgpio-dev)
- g++ ≥ 11
## Build and run
1. git clone https://github.com/maxrob440/Sonar.git
2. cd Sonar
3. cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
4. cmake --build build --parallel
5. ./build/Sonar

By Max Robertson
