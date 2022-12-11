#include "ParticleUpdaters.hpp"

void FloorUpdater::update(ParticleData *particles, float dt)
{
    size_t end_id = particles->alive_count;
    for (size_t i = 0; i < end_id; ++i)
    {
        if (particles->position.at(i).y < floor_level)
            particles->position.at(i).y = floor_level;
    }
}

void GravityUpdater::update(ParticleData *particles, float dt)
{
    size_t end_id = particles->alive_count;
    for (size_t i = 0; i < end_id; ++i)
        particles->acceleration.at(i) += gravity;
}

void EulerUpdater::update(ParticleData *particles, float dt)
{
    size_t end_id = particles->alive_count;
    for (size_t i = 0; i < end_id; ++i)
    {
        particles->velocity.at(i) += particles->acceleration.at(i) * dt;
        particles->position.at(i) += particles->velocity.at(i) * dt;
        particles->acceleration.at(i) = ofVec3f(0.f);
    }
}

void TimeUpdater::update(ParticleData *particles, float dt)
{
    size_t end_id = particles->alive_count;
    for (size_t i = 0; i < end_id; ++i)
    {
        particles->time.at(i).x -= dt;
        particles->time.at(i).z = particles->time.at(i).x * particles->time.at(i).y;
        if (particles->time.at(i).x <= 0)
        {
            particles->kill(i);
            end_id = particles->alive_count < particles->count ? particles->alive_count : particles->count;
        }
    }
}

void TimeColorUpdater::update(ParticleData *particles, float dt)
{
    size_t end_id = particles->alive_count;
    for (size_t i = 0; i < end_id; ++i)
        particles->color.at(i).a = particles->time.at(i).z * 255.f;
}