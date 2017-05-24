#include "RodConstraint.h"
#include "LambdaSolver.h"
#include <GL/glut.h>
#include "armadillo"

using namespace arma;

RodConstraint::RodConstraint(Particle *p1, Particle *p2, double dist) :
        m_p1(p1), m_p2(p2), m_dist(dist) {
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
    new LambdaSolver(
            getJ(),
            getW(),
            getJDot(),
            getqDot(),
            getQ()
    );
}

mat RodConstraint::getq() {
    mat MatrixQ(4, 1, fill::zeros);
    MatrixQ[0, 0] = m_p1->m_Position[0];
    MatrixQ[1, 0] = m_p1->m_Position[1];
    MatrixQ[2, 0] = m_p2->m_Position[0];
    MatrixQ[3, 0] = m_p2->m_Position[1];
    return MatrixQ;
}

double RodConstraint::getC() {
    return pow((m_p1->m_Position[0] - m_p2->m_Position[0]), 2.0) + pow( (m_p1->m_Position[0] - m_p2->m_Position[1]), 2.0 ) - pow(m_dist, 2.0);
}

/**
 * Partial derivatives of position with respect to x1, x2, y1, y2
 *
 * @return Matrix where on each row the partial derivative w.r.t. a variable (x1, x2, y1, y2) is
 * In each column we have the formulas from C, but since we only have one it has only one column
 */
mat RodConstraint::getJ() {
    mat MatrixJ(4, 1, fill::zeros);
    MatrixJ[0, 0] = 2 * (m_p1->m_Position[0] - m_p2->m_Position[0]);
    MatrixJ[0, 1] = 2 * (m_p1->m_Position[1] - m_p2->m_Position[1]);
    MatrixJ[0, 2] = 2 * (m_p1->m_Position[0] - m_p2->m_Position[0]);
    MatrixJ[0, 3] = 2 * (m_p1->m_Position[1] - m_p2->m_Position[1]);

    return MatrixJ;
}

mat RodConstraint::getW() {
    mat MatrixW(4, 4, fill::zeros);
    MatrixW[0, 0] = 1 / (m_p1->mass);
    MatrixW[1, 1] = 1 / (m_p1->mass);
    MatrixW[2, 2] = 1 / (m_p2->mass);
    MatrixW[3, 3] = 1 / (m_p1->mass);
    return MatrixW;
}

/**
 * Partial derivatives of the position values is the velocity
 * @return
 */
mat RodConstraint::getqDot() {
    mat MatrixQDot(4, 1, fill::zeros);
    MatrixQDot[0, 0] = m_p1->m_Velocity[0];
    MatrixQDot[1, 0] = m_p1->m_Velocity[1];
    MatrixQDot[2, 0] = m_p2->m_Velocity[0];
    MatrixQDot[3, 0] = m_p2->m_Velocity[1];
    return MatrixQDot;
}

mat RodConstraint::getJDot() {
    mat MatrixJDot(4, 1, fill::zeros);
    MatrixJDot[0, 0] = 2 * (m_p1->m_Velocity[0] - m_p2->m_Velocity[0]);
    MatrixJDot[0, 1] = 2 * (m_p1->m_Velocity[1] - m_p2->m_Velocity[1]);
    MatrixJDot[0, 2] = 2 * (m_p1->m_Velocity[0] - m_p2->m_Velocity[0]);
    MatrixJDot[0, 3] = 2 * (m_p1->m_Velocity[1] - m_p2->m_Velocity[1]);
    return MatrixJDot;
}

/**
 * Force factor
 * @return
 */
mat RodConstraint::getQ() {
    mat MatrixQ(4, 1, fill::zeros);
    MatrixQ[0, 0] = m_p1->force[0];
    MatrixQ[1, 0] = m_p1->force[1];
    MatrixQ[2, 0] = m_p2->force[0];
    MatrixQ[3, 0] = m_p2->force[1];
    return MatrixQ;
}
