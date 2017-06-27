//
// Created by Tomirio on 27-6-2017.
//

#include "ParticleSystem.h"
#include "../constraints/LambdaSolver.h"

ParticleSystem::ParticleSystem() : t(0) {

}

void ParticleSystem::clearForces() {
    for (auto &particle: particles) {
        particle->m_Force = Vec2f(0, 0);
    }
}

void ParticleSystem::solveConstraints() {
    LambdaSolver::solve(particles, constraints, 60, 5);
}

void ParticleSystem::applyForces() {
    for (auto &force: forces) {
        force->computeForce();
    }
}

void ParticleSystem::draw() {
    drawParticles();
    drawConstraints();
    drawForces();
}

void ParticleSystem::drawParticles() {
    for (auto &particle: particles) {
        particle->draw();
        particle->drawForce();
        particle->drawVelocity();
    }
}

void ParticleSystem::drawConstraints() {
    for (auto &constraint : constraints) {
        constraint->draw();
    }
}

void ParticleSystem::drawForces() {
    for (auto &force : forces) {
        force->draw();
    }
}
