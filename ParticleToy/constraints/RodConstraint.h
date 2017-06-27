#pragma once

#include "../particles/Particle.h"
#include "../forces/ConstraintForce.h"
#include "Eigen/Dense"

using Eigen::MatrixXd;
using Eigen::VectorXd;

class RodConstraint : public ConstraintForce {
public:
    RodConstraint(Particle *p1, Particle *p2, double dist);

    void draw();

    VectorXd getq() override;

    double getC() override;

    MatrixXd getJ() override;

    MatrixXd getW() override;

    MatrixXd getJDot() override;

    VectorXd getqDot() override;

    VectorXd getQ() override;

    double getCdot() override;


private:

    Particle *const m_p1;
    Particle *const m_p2;
    double const m_dist;
};
