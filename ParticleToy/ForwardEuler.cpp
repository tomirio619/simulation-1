//
// Created by Tomirio on 23-5-2017.
//

#include <vector>
#include "Particle.h"
#include "Force.h"
#include "ConstraintForce.h"

namespace ForwardEuler {

    void
    evaluate(std::vector<Particle *> particles, std::vector<Force *> forces, std::vector<ConstraintForce *> constraints,
             double dt) {
        // Clear the forces
        Force::clearForces(particles);
        // Apply forces
        // Apply changes in velocity
        for (auto &particle: particles) {
            particle->m_Velocity += (particle->force * dt);
        }
        // Apply changes in position
        for (auto &particle: particles) {
            particle->m_Position += (particle->m_Velocity * dt);
        }
    }

}

