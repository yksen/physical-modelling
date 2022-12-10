#pragma once

#include "ParticleSystem.hpp"

class TimeUpdater : public ParticleUpdater
{
public:
    void update(ParticleData *particles, float dt) override;
};