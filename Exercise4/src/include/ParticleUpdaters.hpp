#pragma once

#include "ParticleSystem.hpp"

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