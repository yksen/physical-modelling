#pragma once

#include "Particle.hpp"
#include "ParticleEmitters.hpp"
#include "ParticleUpdaters.hpp"

class ParticleSystem
{
public:
    ParticleSystem();
    ParticleSystem(size_t particleCount);

    void draw();
    void update();

    float dt;
    std::vector<unique_ptr<Particle>> particles;
    std::vector<unique_ptr<ParticleEmitter>> emitters;
    std::vector<unique_ptr<ParticleUpdater>> updaters;
};