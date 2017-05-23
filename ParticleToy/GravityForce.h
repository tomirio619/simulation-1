//
// Created by abdullah on 23/05/2017.
//

#ifndef SIMULATION_1_GRAVITYFORCE_H
#define SIMULATION_1_GRAVITYFORCE_H


#include "Force.h"

class GravityForce : public Force {

public:
    GravityForce(std::vector<Particle *> p);

    GravityForce();

    Vec2f computeForce(Particle* p) override;
};


#endif //SIMULATION_1_GRAVITYFORCE_H
