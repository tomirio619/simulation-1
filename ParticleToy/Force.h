//
// Created by abdullah on 23/05/2017.
//

#ifndef SIMULATION_1_FORCE_H
#define SIMULATION_1_FORCE_H


#include <vector>
#include "Particle.h"

class Force {

public:

    Force();

    //Compute the force
    virtual Vec2f computeForce(Particle *p);

    static void clearForces(std::vector<Particle *> particles);

    std::vector<Particle *> particles;
    double gravitationalConstant;

};


#endif //SIMULATION_1_FORCE_H
