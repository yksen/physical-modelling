#pragma once

#include "ParticleSystem.hpp"

class BoxPositionGenerator : public ParticleGenerator
{
public:
    BoxPositionGenerator(ofVec3f origin, ofVec3f range) : origin(origin), range(range){};

    void generate(ParticleData *particles, float dt, size_t start_id, size_t end_id) override;

    ofVec3f origin;
    ofVec3f range;
};

class SpherePositionGenerator : public ParticleGenerator
{
public:
    SpherePositionGenerator(ofVec3f origin, float radius) : origin(origin), radius(radius){};

    void generate(ParticleData *particles, float dt, size_t start_id, size_t end_id) override;

    ofVec3f origin;
    float radius;
};