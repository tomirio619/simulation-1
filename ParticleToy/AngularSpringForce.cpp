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
    float c = cosf(ra); //dot / (len21 * len23);

    // Angular spring
    Vec2f f1 = -ks * (pdiff21 * pdiff23 / (len21 * len23) - c) * pdiff23 / len23;
    Vec2f f2 = -f1;
    Vec2f f3 = -ks * (pdiff21 * pdiff23 / (len21 * len23) - c) * pdiff21 / len21;
    Vec2f f4 = -f3;
    p1->force += f1;
    p3->force += f3;
    p3->force += f2;
    p1->force += f4;

//    Vec2f posdif12 = (p1->m_Position - p2->m_Position);
//    Vec2f posdif32 = (p3->m_Position - p2->m_Position);
//
//    // length of both vectors
//    float length12 = sqrt(posdif12[0] * posdif12[0] + posdif12[1] * posdif12[1]);
//    float length32 = sqrt(posdif32[0] * posdif32[0] + posdif32[1] * posdif32[1]);
//    float length12Sqr = posdif12[0] * posdif12[0] + posdif12[1] * posdif12[1];
//    float length32Sqr = posdif32[0] * posdif32[0] + posdif32[1] * posdif32[1];
//
//    // dot product
//    float dot = (posdif12[0] * posdif32[0] + posdif12[1] * posdif32[1]);
//
//    // square of cosine of the needed angle
//    float cosSqr = dot * dot / length12Sqr / length32Sqr;
//
//    // this is a known trigonometric equality:
//    // cos(alpha * 2) = [ cos(alpha) ]^2 * 2 - 1
//    float cos2 = 2 * cosSqr - 1;
//
//    // Here's the only invocation of the heavy function.
//    // It's a good idea to check explicitly if cos2 is within [-1 .. 1] range
//    const float pi = 3.141592f;
//
//    float alpha2 =
//            (cos2 <= -1) ? pi :
//            (cos2 >= 1) ? 0 :
//            acosf(cos2);
//
//    float rslt = alpha2 / 2;
//
//    float rs = rslt * 180. / pi;
//
//
//    // Now revolve the ambiguities.
//    // 1. If dot product of two vectors is negative - the angle is definitely
//    // above 90 degrees. Still we have no information regarding the sign of the angle.
//
//    // NOTE: This ambiguity is the consequence of our method: calculating the cosine
//    // of the double angle. This allows us to get rid of calling sqrt.
//
//    if (dot < 0)
//        rs = 180 - rs;
//
//    // 2. Determine the sign. For this we'll use the Determinant of two vectors.
//
//    //rs = (int)floor(rs + 0.5);
//    float det = (posdif12[0] * posdif32[1] - posdif12[1] * posdif32[0]);
//    if (det < 0)
//    {
//        rs = -rs;
//    }
//
//    //the angle is from -180 to +180, there are 2 points where it wants to go
//    float restAngle = 0;
//    if (rs < 0)
//    {
//        restAngle = rs + ra;
//    }
//    else
//    {
//        restAngle = rs - ra;
//    }
//
//    Vec2f veldif12 = (p1->m_Velocity - p2->m_Velocity);
//    Vec2f veldif32 = (p3->m_Velocity - p2->m_Velocity);
//
//    p1->force[0] -= ((ks*restAngle) / length12*posdif12[1]) + (kd*veldif12[0]);
//    p1->force[1] += ((ks*restAngle) / length12*posdif12[0]) - (kd*veldif12[1]);
//    p3->force[0] += ((ks*restAngle) / length32*posdif32[1]) - (kd*veldif32[0]);
//    p3->force[1] -= ((ks*restAngle) / length32*posdif32[0]) + (kd*veldif32[1]);
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

