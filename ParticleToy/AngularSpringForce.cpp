//
// Created by Tomirio on 30-5-2017.
//



#include <GL/gl.h>
#include "Force.h"
#include "AngularSpringForce.h"

AngularSpringForce::AngularSpringForce(Particle *p1, Particle *p2, Particle *p3, double r, double ra, double ks,
                                       double kd)
        : Force() {

    this->ks = ks;
    this->kd = kd;
    this->ra = ra;
    this->r = r;
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    particles = {p1, p2, p3};
}

/**
 * @see  // https://stackoverflow.com/questions/14066933/direct-way-of-computing-clockwise-angle-between-2-vectors
 */
void AngularSpringForce::computeForce() {
    // Compute differences in positions
    Vec2f pdiff21 = p1->m_Position - p2->m_Position;
    Vec2f pdiff23 = p3->m_Position - p2->m_Position;
    // Compute differences in velocities
    Vec2f vdiff21 = (p1->m_Velocity - p2->m_Velocity);
    Vec2f vdiff23 = (p3->m_Velocity - p2->m_Velocity);
    // Calculate length of vectors
    float len21 = sqrtf(pdiff21 * pdiff21);
    float len23 = sqrtf(pdiff23 * pdiff23);
    // dot product and determinant
    float dot = pdiff21[0] * pdiff23[0] + pdiff21[1] * pdiff23[1];
    float det = pdiff21[0] * pdiff23[1] - pdiff23[0] * pdiff21[1];
    float c = dot / (len21 * len23);

    Vec2f f1 = -ks * (pdiff21 * pdiff23 / (len21 * len23) - c) * pdiff23 / len23;

    // Angular spring
    p1->force += -ks * (pdiff21 * pdiff23 / (len21 * len23) - c) * pdiff23 / len23;
    p2->force -= p1->force;
    p3->force += -ks * (pdiff21 * pdiff23 / (len21 * len23) - c) * pdiff21 / len21;
    p2->force -= p3->force;
}


void AngularSpringForce::draw() {
    // Lets draw some lines
    glBegin(GL_LINES);
    // Set the color
    glColor3f(0.5f, 0.0f, 1.0f);
    // First line
    glVertex2f(p1->m_Position[0], p1->m_Position[1]);
    glVertex2f(p2->m_Position[0], p2->m_Position[1]);
    // Second line
    glVertex2f(p2->m_Position[0], p2->m_Position[1]);
    glVertex2f(p3->m_Position[0], p3->m_Position[1]);
    glEnd();
}

