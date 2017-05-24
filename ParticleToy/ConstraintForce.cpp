//
// Created by abdullah on 23/05/2017.
//

#include <arma/armadillo>
#include "ConstraintForce.h"

ConstraintForce::ConstraintForce() {}

Vec2f ConstraintForce::computeForce(Particle *p) {
    return Force::computeForce(p);
}

mat ConstraintForce::getQ() {
    return mat(1, 1, fill::zeros);
}

mat ConstraintForce::getqDot() {
    return mat(1, 1, fill::zeros);
}

mat ConstraintForce::getq() {
    return mat(1, 1, fill::zeros);
}

mat ConstraintForce::getJDot() {
    return mat(1, 1, fill::zeros);
}

mat ConstraintForce::getJ() {
    return mat(1, 1, fill::zeros);
}

mat ConstraintForce::getW() {
    return mat(1, 1, fill::zeros);
}

Vec2f ConstraintForce::getCdot() {
    return {0};
}

double ConstraintForce::getC() {
    return 0.0;
}