//
// Created by Tomirio on 30-5-2017.
//

#ifndef SIMULATION_1_ANGULARSPRINGFORCE_H
#define SIMULATION_1_ANGULARSPRINGFORCE_H


#include "Force.h"

class AngularSpringForce : public Force {


public:
    AngularSpringForce();

    AngularSpringForce(Particle *p1, Particle *p2, Particle *p3, double ra, double sk1, double sk2);

    void computeForce() override;

    void draw() override;

private:

    /**
     * Stiffness constant 1
     */
    double sk1;
    /**
     * Stiffness constant 2
     */
    double sk2;
    /**
     * Resting angle
     */
    double ra;
    /**
     * Particles
     */
    Particle * p1;
    Particle * p2;
    Particle * p3;
};




#endif //SIMULATION_1_ANGULARSPRINGFORCE_H
