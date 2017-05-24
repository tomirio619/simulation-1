//
// Created by abdullah on 23/05/2017.
//

#ifndef SIMULATION_1_CONSTRAINTFORCE_H
#define SIMULATION_1_CONSTRAINTFORCE_H


#include "Force.h"
#include "Eigen/Dense"

using Eigen::MatrixXd;

class ConstraintForce : public Force {

public:
    ConstraintForce();

    virtual double getC();
    virtual Vec2f getCdot();
    virtual MatrixXd getq(); //Get q, which is a vector of positions
    virtual MatrixXd getJ(); //Get J, which is the partial derivative vector
    virtual MatrixXd getW();
    virtual MatrixXd getJDot();
    virtual MatrixXd getqDot();
    virtual MatrixXd getQ();

    Vec2f computeForce(Particle *p) override;

};


#endif //SIMULATION_1_CONSTRAINTFORCE_H
