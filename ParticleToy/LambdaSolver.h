//
// Created by abdullah on 23/05/2017.
//

#ifndef SIMULATION_1_LAMBDASOLVER_H
#define SIMULATION_1_LAMBDASOLVER_H

#include "Particle.h"
#include "Eigen/Dense"

using Eigen::MatrixXd;

class LambdaSolver {

public:

    static MatrixXd solveLambda(MatrixXd J, MatrixXd W, MatrixXd Jdot, MatrixXd qDot, MatrixXd Q);
};


#endif //SIMULATION_1_LAMBDASOLVER_H
