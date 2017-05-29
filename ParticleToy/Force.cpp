//
// Created by abdullah on 23/05/2017.
//

#include "Force.h"

Force::Force() {}

void Force::computeForce() {
    return;
}

void Force::clearForces(std::vector<Particle *> particles) {
    for (auto &particle: particles) {
        particle->force = Vec2f(0, 0);
    }
}

void Force::draw() {
    return;
}
