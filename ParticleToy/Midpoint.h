//
// Created by Tomirio on 24-5-2017.
//

#ifndef SIMULATION_1_MIDPOINT_H
#define SIMULATION_1_MIDPOINT_H

#endif //SIMULATION_1_MIDPOINT_H

#include <vector>
#include "Particle.h"
#include "Force.h"
#include "ConstraintForce.h"

namespace Midpoint {
    std::vector<Vec2f> orgPositions;

    void
    evaluate(std::vector<Particle *> particles, std::vector<Force *> forces, std::vector<ConstraintForce *> constraints,
             double dt);
}