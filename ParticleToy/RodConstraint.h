#pragma once

#include "Particle.h"
#include "ConstraintForce.h"
#include "armadillo"

using namespace arma;

class RodConstraint : public ConstraintForce {
public:
    RodConstraint(Particle *p1, Particle *p2, double dist);

    Vec2f computeForce(Particle *p) override;

    void draw();

    mat getq() override;

    double getC() override;

    mat getJ() override;

    mat getW() override;

    mat getJDot() override;

    mat getqDot() override;

    mat getQ() override;


private:

    Particle *const m_p1;
    Particle *const m_p2;
    double const m_dist;
};
