#pragma once

#include <gfx/vec2.h>

class Particle {
public:

    Particle(const Vec2f &ConstructPos, double m);

    void reset();

    void draw();

    int row; //Used to know which row to place the particle in the J matrix
    Vec2f m_ConstructPos;
    Vec2f m_Position;
    Vec2f m_Velocity;
    Vec2f m_Force;
    float m_Mass;

    void drawForce();

    void drawVelocity();
};
