#include <GL/gl.h>
#include "Force.h"
#include "AngularSpringForce.h"

AngularSpringForce::AngularSpringForce(Particle *p1, Particle *p2, Particle *p3, double r, double ra, double ks,
                                       double kd)
        : Force(), m_ks(ks), m_kd(kd), m_ra(ra), m_r(r), m_p1(p1), m_p2(p2), m_p3(p3) {

    particles = {p1, p2, p3};
}

/**
 * @see  // https://stackoverflow.com/questions/14066933/direct-way-of-computing-clockwise-angle-between-2-vectors
 */
void AngularSpringForce::computeForce() {
    // Compute differences in positions
    Vec2f pdiff21 = m_p1->m_Position - m_p2->m_Position;
    Vec2f pdiff23 = m_p3->m_Position - m_p2->m_Position;
    // Compute differences in velocities
    Vec2f vdiff21 = m_p1->m_Velocity - m_p2->m_Velocity;
    Vec2f vdiff23 = m_p2->m_Velocity - m_p3->m_Velocity;
    // Calculate length of vectors
    float len21 = sqrtf(pdiff21 * pdiff21);
    float len23 = sqrtf(pdiff23 * pdiff23);
    // dot product and determinant for testing purposes
    float dot = pdiff21[0] * pdiff23[0] + pdiff21[1] * pdiff23[1];
    float det = pdiff21[0] * pdiff23[1] - pdiff23[0] * pdiff21[1];
    float c = cosf(m_ra);
    float curC = (pdiff21 * pdiff23) / (len21 * len23);
    // Put spring force on first arm
    Vec2f sfp1 = (m_ks * (len21 - m_r) + m_kd * (vdiff21 * pdiff21) / len21) * (pdiff21 / len21);
    m_p1->m_Force -= sfp1;
    m_p2->m_Force += sfp1;

    // Put spring force on second arm
    Vec2f sfp3 = (m_ks * (len23 - m_r) + m_kd * (vdiff23 * pdiff23) / len23) * (pdiff23 / len23);
    m_p3->m_Force -= sfp3;
    m_p2->m_Force += sfp3;

    // Angular springs
    Vec2f f1 = -m_ks * (curC - c) * pdiff23 / len23;
    Vec2f f3 = -m_ks * (curC - c) * pdiff21 / len21;
    m_p1->m_Force += f1;
    m_p3->m_Force += f3;
}


void AngularSpringForce::draw() {
    // Lets draw some lines
    glBegin(GL_LINES);
    // Set the color
    glColor3f(0.5f, 0.0f, 1.0f);
    // First line
    glVertex2f(m_p1->m_Position[0], m_p1->m_Position[1]);
    glVertex2f(m_p2->m_Position[0], m_p2->m_Position[1]);
    // Second line
    glVertex2f(m_p2->m_Position[0], m_p2->m_Position[1]);
    glVertex2f(m_p3->m_Position[0], m_p3->m_Position[1]);
    glEnd();
}

