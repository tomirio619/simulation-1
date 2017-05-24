//
// Created by Tomirio on 24-5-2017.
//

#include <vector>
#include "Particle.h"
#include "Force.h"
#include "ConstraintForce.h"
#include "Midpoint.h"

namespace Midpoint {


    void
    evaluate(std::vector<Particle *> particles, std::vector<Force *> forces, std::vector<ConstraintForce *> constraints,
             double dt) {
        unsigned i = 0;
        // Clear previous positions
        orgPositions.clear();
        Force::clearForces(particles);
        // Save current positions as we need them later on
        for (auto &particle: particles) {
            orgPositions.push_back(particle->m_Position);
        }
        // Apply forces

        // Apply changes in velocity
        for (auto &particle: particles) {
            particle->m_Velocity += particle->force * dt;
        }
        // Apply changes in position
        for (auto &particle: particles) {
            particle->m_Position += particle->m_Velocity * dt / 2.0f;
        }
        // Clear the forces
        for (auto &particle: particles) {
            particle->force = Vec2f(0, 0);
        }
        // Apply forces

        // TODO constraints

        // Final evaluation
        for (auto &particle: particles) {
            particle->m_Velocity += particle->force * dt / 2.0f;
            particle->m_Position = orgPositions[i++] +  particle->m_Velocity * dt;
        }

    }
}