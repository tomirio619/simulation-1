#ifndef SIMULATION_1_LAMBDASOLVER_H
#define SIMULATION_1_LAMBDASOLVER_H

#include "../particles/Particle.h"
#include "Eigen/Dense"
#include "../forces/ConstraintForce.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;


class LambdaSolver {

public:
    static void
    solve(std::vector<Particle *> particles, std::vector<ConstraintForce *> constraints, float ks, float kd);

private:

};


#endif //SIMULATION_1_LAMBDASOLVER_H
