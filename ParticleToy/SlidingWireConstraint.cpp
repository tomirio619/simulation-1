//
// Created by abdullah on 29/05/2017.
//

#include <GL/gl.h>
#include "SlidingWireConstraint.h"

SlidingWireConstraint::SlidingWireConstraint(Particle* p1, double height) : ConstraintForce() {

    this->particles.push_back(p1);
    this->height = height;
    this->p1 = p1;

}

double SlidingWireConstraint::getC() {
    return (p1->m_Position[1] - height);
}

double SlidingWireConstraint::getCdot() {
    return (p1->m_Velocity[1]);
}

VectorXd SlidingWireConstraint::getq() {
    VectorXd MatrixQ(2);
    MatrixQ(0) = p1->m_Position[0];
    MatrixQ(1) = p1->m_Position[1];
    return MatrixQ;
}

MatrixXd SlidingWireConstraint::getJ() {
    MatrixXd MatrixJ(1, 2);
    MatrixJ(0, 0) = 0;
    MatrixJ(0, 1) = 1;

    return MatrixJ;
}

MatrixXd SlidingWireConstraint::getW() {
    MatrixXd MatrixW(2, 2);
    MatrixW(0, 0) = 1 / (p1->mass);
    MatrixW(1, 1) = 1 / (p1->mass);
    return MatrixW;
}

MatrixXd SlidingWireConstraint::getJDot() {
    MatrixXd MatrixJ(1, 2);
    MatrixJ(0, 0) = 0;
    MatrixJ(0, 1) = 0;

    return MatrixJ;
}

VectorXd SlidingWireConstraint::getqDot() {
    VectorXd MatrixQ(2);
    MatrixQ(0) = p1->m_Velocity[0];
    MatrixQ(1) = p1->m_Velocity[1];
    return MatrixQ;
}

VectorXd SlidingWireConstraint::getQ() {
    VectorXd MatrixQ(2);
    MatrixQ(0) = p1->force[0];
    MatrixQ(1) = p1->force[1];
    return MatrixQ;
}

void SlidingWireConstraint::draw() {
    glBegin(GL_LINES);
    glColor3f(0, 1, 0);
    glVertex2f(-1, this->height);
    glColor3f(0, 1, 0);
    glVertex2f(1, this->height);
    glEnd();
}
