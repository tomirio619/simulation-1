//
// Created by Tomirio on 30-5-2017.
//



#include <GL/gl.h>
#include "Force.h"
#include "AngularSpringForce.h"

AngularSpringForce::AngularSpringForce(Particle *p1, Particle *p2, Particle *p3, double ra, double sk1, double sk2)
        : Force() {

    this->sk1 = sk1;
    this->sk2 = sk2;
    this->ra = ra;
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
    Vec2f pdiff12 = p1->m_Position - p2->m_Position;
    Vec2f pdiff32 = p3->m_Position - p2->m_Position;
    // Calculate lenght of vectors
    float len12 = sqrtf(pdiff12 * pdiff12);
    float len32 = sqrtf(pdiff32 * pdiff32);
    // dot product and determinant
    float dot = pdiff12[0] * pdiff32[0] + pdiff12[1] * pdiff32[1];
    float det = pdiff12[0] * pdiff32[1] - pdiff32[0] * pdiff12[1];
    float angle = atan2f(det, dot) * 180.0f / M_PI;

    Vec2f vdiff12 = (p1->m_Velocity - p2->m_Velocity);
    Vec2f vdiff32 = (p3->m_Velocity - p2->m_Velocity);

    ra = dot < 0 ? 180 - angle : ra;
    angle = det < 0 ? -angle : angle;
    float restAngle = angle < 0 ? angle + ra : angle - ra;

    p1->force[0] -= ((sk1 * restAngle) / len12 * pdiff12[1]) + (sk2 * vdiff12[0]);
    p1->force[1] += ((sk1 * restAngle) / len12 * pdiff12[0]) - (sk2 * vdiff12[1]);
    p3->force[0] += ((sk1 * restAngle) / len32 * pdiff32[1]) - (sk2 * vdiff32[0]);
    p3->force[1] -= ((sk1 * restAngle) / len32 * pdiff32[0]) + (sk2 * vdiff32[1]);
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

