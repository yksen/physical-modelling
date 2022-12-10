#pragma once

#include "Particle.hpp"

class ParticleSystem
{
public:
    ParticleSystem();
    ParticleSystem(size_t particleCount);

    void draw();
    void update();

    std::vector<unique_ptr<Particle>> particles;
    float dt;
};