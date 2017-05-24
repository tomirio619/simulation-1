//
// Created by abdullah on 23/05/2017.
//

#include "LambdaSolver.h"
#include "armadillo"
#include "Particle.h"

using namespace std;
using namespace arma;

/**
 * Documentation of the Armadillo
 * http://arma.sourceforge.net/docs.html
 */

LambdaSolver::LambdaSolver(mat J, mat W, mat Jdot, mat qDot, mat Q) {
    mat JWJ = J * W * J.t();
    mat JWJInv = JWJ.i();
    mat JdotQdot = -Jdot*qDot.t();
    mat JWQ = J * W * Q.t();

    mat LambdaT = JWJInv * (-JdotQdot - JWQ);
    mat Lambda = LambdaT.t();

    mat QHat = Lambda * J;
}

