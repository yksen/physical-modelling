#include "ParticleGenerators.hpp"

void TimeGenerator::generate(ParticleData *particles, float dt, size_t start_id, size_t end_id)
{
    for (size_t i = start_id; i < end_id; ++i)
    {
        float lifetime = ofRandom(min, max);
        particles->time.at(i) = ofVec3f(lifetime, 1.0f / lifetime, 0.f);
    }
}

void RandomColorGenerator::generate(ParticleData *particles, float dt, size_t start_id, size_t end_id)
{
    for (size_t i = start_id; i < end_id; ++i)
    {
        particles->color.at(i) = ofColor(
            ofRandom(min.r, max.r),
            ofRandom(min.g, max.g),
            ofRandom(min.b, max.b));
    }
}

void BoxPositionGenerator::generate(ParticleData *particles, float dt, size_t start_id, size_t end_id)
{
    for (size_t i = start_id; i < end_id; ++i)
    {
        particles->position.at(i) = ofVec3f(
            ofRandom(origin.x - range.x, origin.x + range.x),
            ofRandom(origin.y - range.y, origin.y + range.y),
            ofRandom(origin.z - range.z, origin.z + range.z));
    }
}

void CylinderPositionGenerator::generate(ParticleData *particles, float dt, size_t start_id, size_t end_id)
{
    for (size_t i = start_id; i < end_id; ++i)
    {
        float theta = ofRandom(2 * PI);
        float u = ofRandom(radius) + ofRandom(radius);
        float r = u > radius ? 2 - u : u;
        float x = origin.x + r * cos(theta);
        float y = origin.y + ofRandom(-height / 2, height / 2);
        float z = origin.z + r * sin(theta);
        particles->position.at(i) = ofVec3f(x, y, z);
    }
}

void SpherePositionGenerator::generate(ParticleData *particles, float dt, size_t start_id, size_t end_id)
{
    for (size_t i = start_id; i < end_id; ++i)
    {
        float theta = ofRandom(0, 2 * PI);
        float phi = ofRandom(0, 2 * PI);
        float x = origin->x + radius * sin(theta) * cos(phi);
        float y = origin->y + radius * sin(theta) * sin(phi);
        float z = origin->z + radius * cos(theta);
        particles->position.at(i) = ofVec3f(x, y, z);
    }
}

void VelocityGenerator::generate(ParticleData *particles, float dt, size_t start_id, size_t end_id)
{
    for (size_t i = start_id; i < end_id; ++i)
    {
        particles->velocity.at(i) = ofVec3f(
            ofRandom(min.x, max.x),
            ofRandom(min.y, max.y),
            ofRandom(min.z, max.z));
    }
}