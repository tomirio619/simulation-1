//
// Created by abdullah on 23/05/2017.
//

#include "ConstraintForce.h"
#include "Eigen/Dense"

using Eigen::MatrixXd;

ConstraintForce::ConstraintForce() {}

Vec2f ConstraintForce::computeForce(Particle *p) {
    return Force::computeForce(p);
}

MatrixXd ConstraintForce::getQ() {
    MatrixXd matrix(1,1);
    return matrix;
}

MatrixXd ConstraintForce::getqDot() {
    MatrixXd matrix(1,1);
    return matrix;
}

MatrixXd ConstraintForce::getq() {
    MatrixXd matrix(1,1);
    return matrix;
}

MatrixXd ConstraintForce::getJDot() {
    MatrixXd matrix(1,1);
    return matrix;
}

MatrixXd ConstraintForce::getJ() {
    MatrixXd matrix(1,1);
    return matrix;
}

MatrixXd ConstraintForce::getW() {
    MatrixXd matrix(1,1);
    return matrix;
}

Vec2f ConstraintForce::getCdot() {
    return {0};
}

double ConstraintForce::getC() {
    return 0.0;
}