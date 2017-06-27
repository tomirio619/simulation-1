#include "SetUp.h"
#include "../forces/SpringForce.h"
#include "../forces/GravityForce.h"
#include "../constraints/RodConstraint.h"
#include "../constraints/CircularWireConstraint.h"
#include "../constraints/SlidingWireConstraint.h"
#include "../forces/HorizontalForce.h"
#include "../forces/WallForce.h"
#include "../forces/AngularSpringForce.h"

float particleMass = 1.0f;
Vec2f center = Vec2f(0.0, 0.0);

void SetUp::setUpGravity(ParticleSystem &particleSystem) {
    Particle *p1 = new Particle(center, particleMass);
    Particle *p2 = new Particle(Vec2f(0.2, 0.0), particleMass);

    particleSystem.particles.push_back(p1);
    particleSystem.particles.push_back(p2);
    Force *gravityOne = new GravityForce(particleSystem.particles);
    particleSystem.forces.push_back(gravityOne);
}

void SetUp::setUpSpringforce(ParticleSystem &particleSystem) {
    double restLength = 0.5;
    Particle *p1 = new Particle(Vec2f(0.0, 0.0), particleMass);
    Particle *p2 = new Particle(Vec2f(0.0, -0.2f), particleMass);

    particleSystem.particles.push_back(p1);
    particleSystem.particles.push_back(p2);

    Force *springForce = new SpringForce(p1, p2, restLength, 0.1, 0.1);

    particleSystem.forces.push_back(springForce);
}

void SetUp::setUpRodConstraint(ParticleSystem &particleSystem) {
    Particle *centerParticle = new Particle(center, particleMass);
    Particle *bottomParticle = new Particle(Vec2f(0.0, -0.2f), particleMass);

    particleSystem.particles.push_back(centerParticle);
    particleSystem.particles.push_back(bottomParticle);

    ConstraintForce *rodConstraintForce = new RodConstraint(bottomParticle, centerParticle, 0.2);
    particleSystem.constraints.push_back(rodConstraintForce);

    std::vector<Particle *> gravityParticles;
    gravityParticles.push_back(bottomParticle);
    Force *gravityForce = new GravityForce(gravityParticles);
    particleSystem.forces.push_back(gravityForce);
}

void SetUp::setUpCircularConstraint(ParticleSystem &particleSystem) {
    Particle *rightParticle = new Particle(Vec2f(0.2, 0.0), particleMass);
    particleSystem.particles.push_back(rightParticle);

    std::vector<Particle *> gravityParticles;
    gravityParticles.push_back(rightParticle);
    Force *gravity = new GravityForce(gravityParticles);
    particleSystem.forces.push_back(gravity);

    ConstraintForce *circularWire = new CircularWireConstraint(rightParticle, center, 0.2f);
    particleSystem.constraints.push_back(circularWire);
}

void SetUp::setUpHorizontalConstraint(ParticleSystem &particleSystem) {
    Particle *lineParticle = new Particle(center, particleMass);
    particleSystem.particles.push_back(lineParticle);

    ConstraintForce *slidingWire = new SlidingWireConstraint(lineParticle, 0.4);
    particleSystem.constraints.push_back(slidingWire);

    Force *horizontalForce = new HorizontalForce(lineParticle, 0.01f);
    Force *gravityForce = new GravityForce(particleSystem.particles);
    particleSystem.forces.push_back(horizontalForce);
    particleSystem.forces.push_back(gravityForce);
}

void SetUp::setUpMixedConstraint(ParticleSystem &particleSystem) {
    Particle *lineParticle = new Particle(Vec2f(0.1, 0.4), particleMass);
    Particle *circleParticle = new Particle(Vec2f(0.0, 0.2), particleMass);
    particleSystem.particles.push_back(lineParticle);
    particleSystem.particles.push_back(circleParticle);

    ConstraintForce *slidingWire = new SlidingWireConstraint(lineParticle, 0.4);
    particleSystem.constraints.push_back(slidingWire);

    ConstraintForce *circularWire = new CircularWireConstraint(circleParticle, center, 0.2f);
    particleSystem.constraints.push_back(circularWire);

    ConstraintForce *rodConstraint = new RodConstraint(lineParticle, circleParticle, 0.5f);
    particleSystem.constraints.push_back(rodConstraint);

    std::vector<Particle *> gravity;
    gravity.push_back(circleParticle);
    Force *gravityForce = new GravityForce(gravity);
    particleSystem.forces.push_back(gravityForce);
}

void SetUp::setUpSlidingCloth(ParticleSystem &particleSystem, int N) {
    Vec2f center = Vec2f(0, 0);
    float spacing = 0.2f;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            Particle *p = new Particle(Vec2f(center[0] + j * spacing, center[1] - i * spacing), 1.0f);
            particleSystem.particles.push_back(p);
            if (i == 0) {
                particleSystem.constraints.push_back(new SlidingWireConstraint(p, 0.4));
            }

            if (j > 0) {
                particleSystem.forces.push_back(
                        new SpringForce(particleSystem.particles[N * i + j], particleSystem.particles[N * i + j - 1],
                                        spacing, 1, 1));
            }

            if (i > 0) {
                particleSystem.forces.push_back(
                        new SpringForce(particleSystem.particles[N * i + j], particleSystem.particles[N * i + j - N],
                                        spacing, 1, 1));
            }
        }
    }

}

void SetUp::setUpSlidingClothWall(ParticleSystem &particleSystem, int size) {
    setUpSlidingCloth(particleSystem, size);

    for (int i = 0; i < size * size; ++i) {
        //Set the wall after all the constraints (at the right side) and add an additional half offset between the
        //last particle column and the wall
        Force *wall = new WallForce(particleSystem.particles[i], size * 0.2 + 0.1f);
        particleSystem.forces.push_back(wall);
    }
}

void SetUp::setUpAngularSpring(ParticleSystem &particleSystem) {
    particleSystem.clearForces();
    const float dist = 0.2;
    Vec2f center = Vec2f(0, -0.5f);
    Vec2f left = Vec2f(-dist, 0);
    Vec2f right = Vec2f(dist, 0);
    Particle *p1 = new Particle(left, 1);
    Particle *p2 = new Particle(center, 1);
    Particle *p3 = new Particle(right, 1);
    Force *angularSpringForce = new AngularSpringForce(p1, p2, p3, 0.5, 70, 0.1, 0.001);
    particleSystem.particles.push_back(p1);
    particleSystem.particles.push_back(p2);
    particleSystem.particles.push_back(p3);
    particleSystem.forces.push_back(angularSpringForce);
//    Force *dampForce = new DampForce(pVector, 0.9);
//    forces.push_back(dampForce);
    return;
}
