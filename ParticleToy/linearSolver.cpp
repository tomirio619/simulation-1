#include <iostream>
#include "linearSolver.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

// vector helper functions
//

void vecAddEqual(int n, double r[], double v[]) {
    for (int i = 0; i < n; i++)
        r[i] = r[i] + v[i];
}

void vecDiffEqual(int n, double r[], double v[]) {
    for (int i = 0; i < n; i++)
        r[i] = r[i] - v[i];
}

void vecAssign(int n, double v1[], double v2[]) {
    for (int i = 0; i < n; i++)
        v1[i] = v2[i];
}

void vecTimesScalar(int n, double v[], double s) {
    for (int i = 0; i < n; i++)
        v[i] *= s;
}

double vecDot(int n, double v1[], double v2[]) {
    double dot = 0;
    for (int i = 0; i < n; i++)
        dot += v1[i] * v2[i];
    return dot;
}

double vecSqrLen(int n, double v[]) {
    return vecDot(n, v, v);
}


/**
 * In mathematics, the conjugate gradient method is an algorithm for the numerical solution of particular systems
 * of linear equations, namely those whose matrix is symmetric and positive-definite.
 * @param n
 * @param A
 * @param x
 * @param b
 * @param epsilon
 * @param steps
 * @return
 */
VectorXd ConjGrad(int n, MatrixXd A, VectorXd x, VectorXd b,
                  double epsilon,    // how low should we go?
                  int *steps) {
    int i, iMax;
    double alpha, beta, rSqrLen, rSqrLenOld, u;

    VectorXd r(n);
    VectorXd d(n);
    VectorXd t(n);
    VectorXd temp(n);

    for (int k = 0; k < b.size(); ++k) {
        x[k] = b[k];
    }

    for (int l = 0; l < b.size(); ++l) {
        r[l] = b[l];
    }

//    vecAssign(n, r, b);
//    A->matVecMult(x, temp);
    temp = A * x;

//    vecDiffEqual(n, r, temp);
    r = r - temp;

//    rSqrLen = vecSqrLen(n, r);
    rSqrLen = r.size();

//    vecAssign(n, d, r);
    for (int j = 0; j < r.size(); ++j) {
        d[j] = r[j];
    }

    i = 0;
    if (*steps)
        iMax = *steps;
    else
        iMax = MAX_STEPS;

    if (rSqrLen > epsilon)
        while (i < iMax) {
            i++;
//            A->matVecMult(d, t);
            t = A * d;
//            u = vecDot(n, d, t);
            u = d.dot(t);


            if (u == 0) {
                printf("(SolveConjGrad) d'Ad = 0\n");
                break;
            }

            // How far should we go?
            alpha = rSqrLen / u;

            // Take a step along direction d
//            vecAssign(n, temp, d);
            for (int j = 0; j < d.size(); ++j) {
                temp[j] = d[j];
            }
//            vecTimesScalar(n, temp, alpha);
            temp = alpha * temp;
//            vecAddEqual(n, x, temp);
            x = x + temp;

//            std::cout << x << std::endl;

            if (i & 0x3F) {
//                vecAssign(n, temp, t);
                for (int j = 0; j < t.size(); ++j) {
                    temp[j] = t[j];
                }
//                vecTimesScalar(n, temp, alpha);
                temp = alpha * temp;
//                vecDiffEqual(n, r, temp);
                r = r - temp;
            } else {
                // For stability, correct r every 64th iteration
//                vecAssign(n, r, b);
                for (int j = 0; j < b.size(); ++j) {
                    r[j] = b[j];
                }
//                A->matVecMult(x, temp);
                temp = A * x;
//                vecDiffEqual(n, r, temp);
                r = r - temp;
            }

            rSqrLenOld = rSqrLen;
//            rSqrLen = vecSqrLen(n, r);
            rSqrLen = r.size();

            // Converged! Let's get out of here
            if (rSqrLen <= epsilon)
                break;

            // Change direction: d = r + beta * d
            beta = rSqrLen / rSqrLenOld;
//            vecTimesScalar(n, d, beta);
            d = beta * d;
//            vecAddEqual(n, d, r);
            d = d + r;
        }

    // free memory

//    free(r);
//    free(d);
//    free(t);
//    free(temp);

    *steps = i;
    return b;
}


