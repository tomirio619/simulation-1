//
// Created by abdullah on 23/05/2017.
//

#ifndef SIMULATION_1_CONSTRAINTFORCE_H
#define SIMULATION_1_CONSTRAINTFORCE_H


#include "Force.h"
#include "armadillo"

using namespace arma;

class ConstraintForce : public Force {

public:
    ConstraintForce();

    virtual double getC();
    virtual Vec2f getCdot();
    virtual mat getq(); //Get q, which is a vector of positions
    virtual mat getJ(); //Get J, which is the partial derivative vector
    virtual mat getW();
    virtual mat getJDot();
    virtual mat getqDot();
    virtual mat getQ();

    Vec2f computeForce(Particle *p) override;

};


#endif //SIMULATION_1_CONSTRAINTFORCE_H
