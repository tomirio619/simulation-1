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
using Eigen::VectorXd;

/**
 * Compute the constraint force
 * @param J
 * @param W
 * @param Jdot
 * @param qDot
 * @param Q
 * @return
 */
MatrixXd LambdaSolver::solveLambda(MatrixXd J, MatrixXd W, MatrixXd Jdot, VectorXd qDot, VectorXd Q) {

    //See http://graphics.stanford.edu/courses/cs348c-16-fall/CS348C_F16_HW1_Constraints.pdf
    //Lambda = (JWJ^T)^-1 (Jdot qdot JWf)

    MatrixXd JW = J * W;
    MatrixXd JWJT = JW * J.transpose();
//    MatrixXd JWJInv = JWJT.inverse();

    MatrixXd JdotQdot = -Jdot*qDot;

    MatrixXd JWQ = JW * Q;
//    MatrixXd LambdaT = JWJInv * (-JdotQdot - JWQT);
//    MatrixXd Lambda = LambdaT.transpose();
    MatrixXd RHS = -JdotQdot - JWQ;

//    MatrixXd QHat = Lambda * J;

    //Need to solve Ax = b, where x is the constraint force.
    //A = JWJ^t
    //B = -Jqdot - JWQ^transpose

    ConjugateGradient<MatrixXd, Eigen::Lower|Eigen::Upper, Eigen::IdentityPreconditioner> cg;
    cg.compute(JWJT);
    VectorXd x =  cg.solve(RHS);
    MatrixXd QHat =  x * J;
    return QHat;


//    MatrixXd RHS = (-JdotQdot - JWQ);
//
//    ConjugateGradient<MatrixXd, Eigen::Lower|Eigen::Upper, Eigen::IdentityPreconditioner> cg;
//    cg.compute(JWJT);
//    MatrixXd dest(1, 4);
//    dest = cg.solve(RHS);
//    MatrixXd forces = dest * J.transpose();
//
//    return forces;


    //Another attempt, try to rebuild the matrix

}


