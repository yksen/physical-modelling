#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem()
{
}

ParticleSystem::ParticleSystem(size_t particleCount)
{
    for (size_t i = 0; i < particleCount; i++)
        particles.push_back(make_unique<Particle>());
}

void ParticleSystem::draw()
{
    for (auto &particle : particles)
        particle->draw();
}

void ParticleSystem::update()
{
}