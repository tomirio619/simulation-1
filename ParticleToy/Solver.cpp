#include "Particle.h"
#include "Force.h"
#include "ForwardEuler.h"
#include "ConstraintForce.h"
#include "Midpoint.h"
#include "RK4.h"


void simulation_step(std::vector<Particle *> particles, std::vector<Force *> forces, std::vector<ConstraintForce *> constraints, float dt, int integrationSchemeIndex) {
    switch (integrationSchemeIndex){
        case 0:
            ForwardEuler::evaluate(particles, forces, constraints, dt);
            break;
        case 1:
            Midpoint::evaluate(particles, forces, constraints, dt);
            break;
        case 2:
            RK4::evaluate(particles, forces, constraints, dt);
            break;
    }
}

