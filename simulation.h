#ifndef SIMULATION_H
#define SIMULATION_H
#include <vector>
#include "coordinate.h"

class Simulation
{
public:
    vector<vector<double>> obstacles;
    Coordinate raytrace(Coordinate coords);
    Simulation();
};

#endif // SIMULATION_H
