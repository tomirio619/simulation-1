#include "Particle.h"
#include "Force.h"

#include <vector>

#define DAMP 0.98f
#define RAND (((rand()%2000)/1000.f)-1.f)

void clear_forces(std::vector<Particle *> particles) {
    for (int i = 0; i < particles.size(); ++i) {
        particles[i]->force = Vec2f(0, 0);
    }
}

void simulation_step(std::vector<Force *> forces, float dt) {

    int ii, size = forces.size();

    for (ii = 0; ii < size; ii++) {
        int particle, particlesSize = forces[ii]->particles.size();
        clear_forces(forces[ii]->particles);
        for (int particle = 0; particle < particlesSize; ++particle) {
            Particle* currentParticle = forces[ii]->particles[particle];
            currentParticle->force += forces[ii]->computeForce(currentParticle);
            Vec2f a = currentParticle->force / currentParticle->mass;
            currentParticle->m_Position += dt * currentParticle->m_Velocity;
            currentParticle->m_Velocity += dt * a;
        }
    }

}

