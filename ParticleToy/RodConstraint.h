#pragma once

#include "Particle.h"
#include "ConstraintForce.h"
#include "Eigen/Dense"

using Eigen::MatrixXd;

class RodConstraint : public ConstraintForce {
public:
    RodConstraint(Particle *p1, Particle *p2, double dist);

    Vec2f computeForce(Particle *p) override;

    void draw();

    MatrixXd getq() override;

    double getC() override;

    MatrixXd getJ() override;

    MatrixXd getW() override;

    MatrixXd getJDot() override;

    MatrixXd getqDot() override;

    MatrixXd getQ() override;


private:

    Particle *const m_p1;
    Particle *const m_p2;
    double const m_dist;
};
