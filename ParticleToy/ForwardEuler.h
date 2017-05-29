//
// Created by Tomirio on 23-5-2017.
//

#include <vector>
#include "Particle.h"
#include "ConstraintForce.h"

#ifndef SIMULATION_1_FORWARDEULER_H
#define SIMULATION_1_FORWARDEULER_H

#endif //SIMULATION_1_FORWARDEULER_H

class ForwardEuler {
public:
    static void evaluate(std::vector<Particle *> particles, std::vector<Force *> forces, std::vector<ConstraintForce *> constraints, float dt);
};