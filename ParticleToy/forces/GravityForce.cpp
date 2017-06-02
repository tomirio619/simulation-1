#include "GravityForce.h"

GravityForce::GravityForce(std::vector<Particle *> p) : Force() {
    this->particles = p;
    this->gravitationalConstant = -9.81f * 0.001f;
}

GravityForce::GravityForce() : Force() {

}

void GravityForce::computeForce() {
    for (auto &particle : particles) {
        particle->m_Force[1] += particle->m_Mass * this->gravitationalConstant;
    }
}

