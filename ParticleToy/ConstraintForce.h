//
// Created by abdullah on 23/05/2017.
//

#ifndef SIMULATION_1_CONSTRAINTFORCE_H
#define SIMULATION_1_CONSTRAINTFORCE_H


#include "Force.h"

class ConstraintForce : public Force {

public:
    ConstraintForce();

    virtual double getC();
    virtual Vec2f getCdot();
    virtual std::vector<Vec2f> getq(); //Get q, which is a vector of positions
    virtual std::vector<Vec2f> getJ(); //Get J, which is the partial derivative vector
    virtual std::vector<double> getW();
    virtual std::vector<Vec2f> getJDot();
    virtual std::vector<Vec2f> getqDot();
    virtual std::vector<Vec2f> getQ();

    Vec2f computeForce(Particle *p) override;

};


#endif //SIMULATION_1_CONSTRAINTFORCE_H
