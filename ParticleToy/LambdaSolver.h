//
// Created by abdullah on 23/05/2017.
//

#ifndef SIMULATION_1_LAMBDASOLVER_H
#define SIMULATION_1_LAMBDASOLVER_H


#include <arma/armadillo>
#include "Particle.h"

class LambdaSolver {

public:

    LambdaSolver(arma::mat J, arma::mat W, arma::mat Jdot, arma::mat qDot, arma::mat Q);
};


#endif //SIMULATION_1_LAMBDASOLVER_H
