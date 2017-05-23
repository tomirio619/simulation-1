//
// Created by abdullah on 23/05/2017.
//

#include "GravityForce.h"

GravityForce::GravityForce(std::vector<Particle *> p) : Force() {
    this->particles = p;
    this->gravitationalConstant = -9.81 * 0.001f;

}

GravityForce::GravityForce() :Force() {

}


Vec2f GravityForce::computeForce(Particle* p) {
    return Vec2f(0, p->mass * this->gravitationalConstant);
}

