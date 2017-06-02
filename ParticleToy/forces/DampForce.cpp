#include "DampForce.h"

DampForce::DampForce(std::vector<Particle *> particles, double damp) : Force(), m_particles(particles), m_damp(damp) {
}

void DampForce::computeForce() {
    for (auto &particle : particles) {
        particle->m_Force -= particle->m_Velocity * m_damp / particle->m_Mass;
    }
}

void DampForce::draw() {
    return;
}
