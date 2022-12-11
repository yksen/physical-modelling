#include "ParticleUpdaters.hpp"

void EulerUpdater::update(ParticleData *particles, float dt)
{
    size_t end_id = particles->alive_count;
    for (size_t i = 0; i < end_id; ++i)
        particles->velocity.at(i) += particles->acceleration.at(i) * dt;
    for (size_t i = 0; i < end_id; ++i)
        particles->position.at(i) += particles->velocity.at(i) * dt;
}

void TimeUpdater::update(ParticleData *particles, float dt)
{
    size_t end_id = particles->alive_count;
    for (size_t i = 0; i < end_id; ++i)
    {
        particles->time.at(i) -= dt;
        if (particles->time.at(i) <= 0)
        {
            particles->kill(i);
            end_id = particles->alive_count < particles->count ? particles->alive_count : particles->count;
        }
    }
}