//
// Created by Tomirio on 23-5-2017.
//

#include <vector>
#include "Particle.h"
#include "Force.h"
#include "ConstraintForce.h"
#include "LambdaSolver.h"
#include "ForwardEuler.h"

void ForwardEuler::evaluate(std::vector<Particle *> particles, std::vector<Force *> forces,
                            std::vector<ConstraintForce *> constraints, float dt) {
    // Clear the forces
    Force::clearForces(particles);
    // Apply forces
    for (auto &force: forces) {
        force->computeForce();
    }

    //Constraints

    // Apply changes in velocity
    for (auto &particle: particles) {
        particle->m_Velocity += (particle->force * dt);
    }
    // Apply changes in position
    for (auto &particle: particles) {
        particle->m_Position += (particle->m_Velocity * dt);
    }
}
