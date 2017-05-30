//
// Created by abdullah on 30/05/2017.
//

#include "HorizontalForce.h"

HorizontalForce::HorizontalForce(Particle* p1, double force) : Force() {

    this->p1 = p1;
    this->force = force;

}

void HorizontalForce::computeForce() {
    this->p1->force += Vec2f(force, 0);
}

void HorizontalForce::draw() {
    Force::draw();
}
