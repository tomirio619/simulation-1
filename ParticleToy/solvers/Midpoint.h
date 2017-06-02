#ifndef SIMULATION_1_MIDPOINT_H
#define SIMULATION_1_MIDPOINT_H

#endif //SIMULATION_1_MIDPOINT_H

#include <vector>
#include "../Particle.h"
#include "../forces/Force.h"
#include "../forces/ConstraintForce.h"

class Midpoint {
public:
    static void
    evaluate(std::vector<Particle *> particles, std::vector<Force *> forces, std::vector<ConstraintForce *> constraints,
             float dt);
};