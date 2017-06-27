//
// Created by Tomirio on 27-6-2017.
//

#ifndef SIMULATION_1_SOLVER_H
#define SIMULATION_1_SOLVER_H


#include "../particles/ParticleSystem.h"
#include "../forces/ConstraintForce.h"
#include <vector>

using namespace std;

class Solver {
public:
    Solver();

    int particleDims(ParticleSystem *p);

    void particleGetState(ParticleSystem *p, vector<float> &dst);

    void particleSetState(ParticleSystem *p, vector<float> &src);

    void particleDerivative(ParticleSystem *p, vector<float> &dst);

    virtual void simulationStep(ParticleSystem *p, float deltaT) = 0;

    void scaleVector(vector<float> &src, float scalar);

    void addVectors(vector<float> &v1, vector<float> &v2, vector<float> &dest);
};


#endif //SIMULATION_1_SOLVER_H
