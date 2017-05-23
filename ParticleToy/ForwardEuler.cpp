//
// Created by Tomirio on 23-5-2017.
//

#include <vector>
#include "Particle.h"
#include "Force.h"
#include "ConstraintForce.h"

void evaluate(std::vector<Particle *> particles, std::vector<Force *> forces, std::vector<ConstraintForce *> constraints, double dt){
    // Clear the forces
    for (auto &particle: particles ){
        particle->force = Vec2f(0.0, 0.0);
    }
    // Apply forces
    for (auto &force: forces ){
        // TODO apply the force to the particle
    }
    // Apply changes in velocity
    for (auto &particle: particles){
        particle->m_Velocity += (particle->force * dt);
    }
    // Apply changes in position
    for (auto &particle: particles){
        particle->m_Position += (particle->m_Velocity * dt);
    }
}

