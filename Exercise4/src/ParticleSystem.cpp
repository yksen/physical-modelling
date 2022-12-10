#include "ParticleSystem.hpp"

void ParticleSystem::draw()
{
    for (auto& particle : particles)
        particle->draw();
}

void ParticleSystem::update()
{
}

void ParticleSystem::addParticle()
{
    particles.push_back(make_unique<Particle>());
}