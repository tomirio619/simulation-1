//
// Created by Tomirio on 23-5-2017.
//

#include <vector>
#include "Particle.h"
#include "RK4.h"
#include "Force.h"
#include "ConstraintForce.h"


/**
 * Clear the forces of the particles
 * @param particles Vector of particles
 */
void clearForces(std::vector<Particle *> particles) {
    // Clear the forces
    for (auto &particle: particles) {
        particle->force = Vec2f(0, 0);
    }
}

/**
 * Apply the forces
 * @param forces
 */
void applyForces(std::vector<Force *> forces) {
    // Apply forces
    for (auto &force: forces) {
        // TODO apply the force to the particle
    }
}

void evaluate(std::vector<Particle *> particles, std::vector<Force *> forces, std::vector<ConstraintForce> constraints, double dt) {
    clearForces(particles);
    applyForces(forces);
    // Remove the previously saved positions
    orgPositions.clear();
    // Save current positions as we need them in every evaluation
    for (auto &particle: particles) {
        orgPositions.push_back(particle->m_Position);
    }
    // Vectors for storing intermediate values
    std::vector<Vec2f> k1s;
    std::vector<Vec2f> k2s;
    std::vector<Vec2f> k3s;
    std::vector<Vec2f> k4s;
    // Counter
    unsigned i = 0;
    // Calculate k1's
    for (auto &particle: particles) {
        particle->m_Velocity += particle->force * dt;
        k1s.push_back(particle->force * dt);
    }

    // Clear and accumulate forces, apply constraints
    clearForces(particles);
    applyForces(forces);
    // TODO constraints

    // Calculate k2's
    for (auto &particle: particles) {
        particle->m_Position += orgPositions[i] + particle->m_Velocity * dt / 2.0f;
        particle->m_Velocity += particle->force * dt;
        k2s.push_back(particle->force + k1s[i] / 2.0f);
    }

    // Clear and accumulate forces, apply constraints
    i = 0;
    clearForces(particles);
    applyForces(forces);
    // TODO constraints

    // Calculate k3's
    for (auto &particle: particles) {
        particle->m_Position += orgPositions[i] + particle->m_Velocity * dt / 2.0f;
        particle->m_Velocity += dt / 2.0f;
        k3s.push_back(particle->force + k2s[i] / 2.0f);
    }

    // Clear and accumulate forces, apply constraints
    i = 0;
    clearForces(particles);
    applyForces(forces);
    // TODO constraints

    // Calculate k4's and do the final evaluation using the original position
    for (auto &particle: particles) {
        particle->m_Position += orgPositions[i] + particle->m_Velocity * dt;
        particle->m_Velocity += dt / 2.0f;
        k4s.push_back(particle->force + k3s[i]);
        particle->m_Position = orgPositions[i] + k1s[i] / 6.0f + k2s[i] / 3.0f + k3s[i] / 3.0f + k4s[i] / 6.0f;
    }

}
