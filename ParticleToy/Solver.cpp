#include "Particle.h"
#include "Force.h"
#include "ForwardEuler.h"
#include "ConstraintForce.h"


void simulation_step(std::vector<Particle *> particles, std::vector<Force *> forces, std::vector<ConstraintForce *> constraints, float dt) {
    ForwardEuler::evaluate(particles, forces, constraints, dt);
}

