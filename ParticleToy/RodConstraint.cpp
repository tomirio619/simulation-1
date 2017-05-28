#include "RodConstraint.h"
#include "LambdaSolver.h"
#include <GL/glut.h>
#include "Eigen/Dense"

using Eigen::MatrixXd;
using Eigen::VectorXd;

RodConstraint::RodConstraint(Particle *p1, Particle *p2, double dist) :
        m_p1(p1), m_p2(p2), m_dist(dist) {
    particles.push_back(m_p1);
    particles.push_back(m_p2);
}

void RodConstraint::draw() {
    glBegin(GL_LINES);
    glColor3f(0.8, 0.7, 0.6);
    glVertex2f(m_p1->m_Position[0], m_p1->m_Position[1]);
    glColor3f(0.8, 0.7, 0.6);
    glVertex2f(m_p2->m_Position[0], m_p2->m_Position[1]);
    glEnd();

}

Vec2f RodConstraint::computeForce(Particle *p) {
    MatrixXd QHat = LambdaSolver::solveLambda(getJ(), getW(), getJDot(), getqDot(), getQ());

    m_p1->force[0] += QHat(0, 0);
    m_p1->force[1] += QHat(0, 1);
    m_p2->force[0] += QHat(0, 2);
    m_p2->force[1] += QHat(0, 3);
}

VectorXd RodConstraint::getq() {
    VectorXd MatrixQ(4);
    MatrixQ(0) = particles[0]->m_Position[0];
    MatrixQ(1) = particles[0]->m_Position[1];
    MatrixQ(2) = particles[1]->m_Position[0];
    MatrixQ(3) = particles[1]->m_Position[1];
    return MatrixQ;
}

double RodConstraint::getC() {
    return pow((particles[0]->m_Position[0] - particles[1]->m_Position[0]), 2.0) + pow( (particles[0]->m_Position[0] - particles[1]->m_Position[1]), 2.0 ) - pow(m_dist, 2.0);
}

/**
 * Partial derivatives of position with respect to x1, x2, y1, y2
 *
 * @return Matrix where on each row the partial derivative w.r.t. a variable (x1, x2, y1, y2) is
 * In each column we have the formulas from C, but since we only have one it has only one column
 */
MatrixXd RodConstraint::getJ() {
    //(rows, column)
    MatrixXd MatrixJ(1, 4);
    MatrixJ(0, 0) = 2 * (particles[0]->m_Position[0] - particles[1]->m_Position[0]);
    MatrixJ(0, 1) = 2 * (particles[0]->m_Position[1] - particles[1]->m_Position[1]);
    MatrixJ(0, 2) = 2 * (particles[1]->m_Position[0] - particles[0]->m_Position[0]);
    MatrixJ(0, 3) = 2 * (particles[1]->m_Position[1] - particles[0]->m_Position[1]);

    return MatrixJ;
}

MatrixXd RodConstraint::getW() {
    MatrixXd MatrixW(4, 4);
    MatrixW(0, 0) = 1 / (particles[0]->mass);
    MatrixW(1, 1) = 1 / (particles[0]->mass);
    MatrixW(2, 2) = 1 / (particles[1]->mass);
    MatrixW(3, 3) = 1 / (particles[1]->mass);
    return MatrixW;
}

/**
 * Partial derivatives of the position values is the velocity
 * @return
 */
VectorXd RodConstraint::getqDot() {
    VectorXd MatrixQDot(4);
    MatrixQDot(0) = particles[0]->m_Velocity[0];
    MatrixQDot(1) = particles[0]->m_Velocity[1];
    MatrixQDot(2) = particles[1]->m_Velocity[0];
    MatrixQDot(3) = particles[1]->m_Velocity[1];
    return MatrixQDot;
}

MatrixXd RodConstraint::getJDot() {
    MatrixXd MatrixJDot(1, 4);
    MatrixJDot(0, 0) = 2 * (particles[0]->m_Velocity[0] - particles[1]->m_Velocity[0]);
    MatrixJDot(0, 1) = 2 * (particles[0]->m_Velocity[1] - particles[1]->m_Velocity[1]);
    MatrixJDot(0, 2) = 2 * (particles[1]->m_Velocity[0] - particles[0]->m_Velocity[0]);
    MatrixJDot(0, 3) = 2 * (particles[1]->m_Velocity[1] - particles[0]->m_Velocity[1]);
    return MatrixJDot;
}

/**
 * Force factor
 * @return
 */
VectorXd RodConstraint::getQ() {
    VectorXd MatrixQ(4);
    MatrixQ(0) = particles[0]->force[0];
    MatrixQ(1) = particles[0]->force[1];
    MatrixQ(2) = particles[1]->force[0];
    MatrixQ(3) = particles[1]->force[1];
    return MatrixQ;
}
