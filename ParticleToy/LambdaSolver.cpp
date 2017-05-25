//
// Created by abdullah on 23/05/2017.
//

#include "LambdaSolver.h"
#include "Eigen/Dense"
#include "linearSolver.h"
#include "Eigen/IterativeLinearSolvers"

using namespace std;
using Eigen::MatrixXd;
using Eigen::ConjugateGradient;

/**
 * Compute the constraint force
 * @param J
 * @param W
 * @param Jdot
 * @param qDot
 * @param Q
 * @return
 */
MatrixXd LambdaSolver::solveLambda(MatrixXd J, MatrixXd W, MatrixXd Jdot, MatrixXd qDot, MatrixXd Q) {
    MatrixXd JW = J * W;
    std::cout << JW << std::endl;
    MatrixXd JWJT = JW * J.transpose();
    MatrixXd JWJInv = JWJT.inverse();
    MatrixXd JdotQdot = -Jdot*qDot.transpose();
    MatrixXd JWQ = JW * Q.transpose();

    MatrixXd LambdaT = JWJInv * (-JdotQdot - JWQ);
    MatrixXd Lambda = LambdaT.transpose();

    MatrixXd QHat = Lambda * J;

    MatrixXd RHS = (-JdotQdot - JWQ);

    ConjugateGradient<MatrixXd, Eigen::Lower|Eigen::Upper, Eigen::IdentityPreconditioner> cg;
    cg.compute(JWJT);
    MatrixXd dest(1, 4);
    dest = cg.solve(RHS);
    MatrixXd forces = dest * J.transpose();

    return forces;
}
