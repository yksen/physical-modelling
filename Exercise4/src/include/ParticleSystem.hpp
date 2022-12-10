#pragma once

#include "Particle.hpp"

class ParticleSystem
{
public:
    void draw();
    void update();

    void addParticle();

    std::vector<unique_ptr<Particle>> particles;
};