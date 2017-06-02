#ifndef SIMULATION_1_DAMPFORCE_H
#define SIMULATION_1_DAMPFORCE_H

#include "Force.h"

class DampForce : public Force {

public:
    DampForce(std::vector<Particle *> particles, double mass);

    void computeForce() override;

    void draw() override;

private:
    std::vector<Particle *> m_particles;
    // The damping constant
    const float m_damp;

};


#endif //SIMULATION_1_DAMPFORCE_H
