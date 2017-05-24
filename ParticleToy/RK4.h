//
// Created by Tomirio on 23-5-2017.
//

#include <vector>
#include "Particle.h"

#ifndef SIMULATION_1_RUNGEKUTTAFOURTH_H
#define SIMULATION_1_RUNGEKUTTAFOURTH_H


// During this evaluation, we will overwrite the velocities for the particles
// Therefore, we have to save them now so we can restore them later.
// We also need to clear this vector before we evaluate.

namespace RK4 {
    std::vector<Vec2f> orgPositions;
}

#endif //SIMULATION_1_RUNGEKUTTAFOURTH_H