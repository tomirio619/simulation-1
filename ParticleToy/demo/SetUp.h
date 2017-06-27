#ifndef SIMULATION_1_SETUP_H
#define SIMULATION_1_SETUP_H


#include <Eigen/StdVector>
#include "../particles/Particle.h"
#include "../forces/Force.h"
#include "../forces/ConstraintForce.h"
#include "../particles/ParticleSystem.h"

class SetUp {

public:
    static void setUpSpringforce(ParticleSystem &p);

    static void setUpGravity(ParticleSystem &p);

    static void setUpRodConstraint(ParticleSystem &p);

    static void setUpCircularConstraint(ParticleSystem &p);

    static void setUpHorizontalConstraint(ParticleSystem &p);

    static void setUpMixedConstraint(ParticleSystem &p);

    static void setUpSlidingCloth(ParticleSystem &p, int size);

    static void setUpSlidingClothWall(ParticleSystem &p, int size);

    static void setUpAngularSpring(ParticleSystem &p);
};


#endif //SIMULATION_1_SETUP_H
