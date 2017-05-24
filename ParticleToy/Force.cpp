//
// Created by abdullah on 23/05/2017.
//

#include "Force.h"

Force::Force() {}

Vec2f Force::computeForce(Particle *p) {
    return 0;
}

void Force::clearForces(std::vector<Particle *> particles) {
    for (auto &particle: particles) {
        particle->force = Vec2f(0, 0);
    }
}
