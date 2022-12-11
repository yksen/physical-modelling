#pragma once

#include "ParticleSystem.hpp"

class GravityUpdater : public ParticleUpdater
{
public:
    void update(ParticleData *particles, float dt) override;

    ofVec3f gravity = ofVec3f(0, -9.81f, 0);
};

class EulerUpdater : public ParticleUpdater
{
public:
    void update(ParticleData *particles, float dt) override;
};

class TimeUpdater : public ParticleUpdater
{
public:
    void update(ParticleData *particles, float dt) override;
};