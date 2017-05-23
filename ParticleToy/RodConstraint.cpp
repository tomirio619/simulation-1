#include "RodConstraint.h"
#include <GL/glut.h>

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

}

std::vector<Vec2f> RodConstraint::getq() {
    std::vector<Vec2f> q;
    q.push_back(m_p1->m_Position);
    q.push_back(m_p2->m_Position);
    return q;
}

double RodConstraint::getC() {
    return pow((m_p1->m_Position[0] - m_p2->m_Position[0]), 2.0) + pow( (m_p1->m_Position[0] - m_p2->m_Position[1]), 2.0 ) - pow(m_dist, 2.0);
}

std::vector<Vec2f> RodConstraint::getJ() {
    std::vector<Vec2f> J;
    J.push_back(2 * (m_p1->m_Position[0] - m_p2->m_Position[0]));
    J.push_back(2 * (m_p1->m_Position[0] - m_p2->m_Position[0]));
    J.push_back(2 * (m_p1->m_Position[1] - m_p2->m_Position[1]));
    J.push_back(2 * (m_p1->m_Position[1] - m_p2->m_Position[1]));
    return J;
}

std::vector<double> RodConstraint::getW() {
    std::vector<double> W;
    W.push_back(1 / (m_p1->mass));
    W.push_back(1 / (m_p2->mass));
    return W;
}

std::vector<Vec2f> RodConstraint::getJDot() {
    std::vector<Vec2f> JDot;

}


