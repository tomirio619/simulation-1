//
// Created by abdullah on 23/05/2017.
//

#include "ConstraintForce.h"

ConstraintForce::ConstraintForce() {}

Vec2f ConstraintForce::computeForce(Particle *p) {
    return Force::computeForce(p);
}

double ConstraintForce::getC() {
    return 0;
}

Vec2f ConstraintForce::getCdot() {
    return 0;
}

std::vector<Vec2f> ConstraintForce::getJ() {
    return {0};
}

std::vector<Vec2f> ConstraintForce::getJDot() {
    return {0};
}


std::vector<Vec2f> ConstraintForce::getQ() {
    return {0};
}

std::vector<Vec2f> ConstraintForce::getq() {
    return {0};
}

std::vector<double> ConstraintForce::getW() {
    return {0};
}

std::vector<Vec2f> ConstraintForce::getqDot() {
    return {0};
}
