//
// Created by Tomirio on 30-5-2017.
//

#ifndef SIMULATION_1_ANGULARSPRINGFORCE_H
#define SIMULATION_1_ANGULARSPRINGFORCE_H


#include "Force.h"

class AngularSpringForce : public Force {


public:
    AngularSpringForce();

    AngularSpringForce(Particle *p1, Particle *p2, Particle *p3, double r, double ra, double ks, double kd);

    void computeForce() override;

    void draw() override;

private:

    /**
     * Stiffness constant
     */
    double ks;
    /**
     * Damping constant
     */
    double kd;
    /**
     * Rest angle
     */
    double ra;

    /**
     * Rest length
     */
    double r;
    /**
     * Particles
     */
    Particle * p1;
    Particle * p2;
    Particle * p3;
};




#endif //SIMULATION_1_ANGULARSPRINGFORCE_H
