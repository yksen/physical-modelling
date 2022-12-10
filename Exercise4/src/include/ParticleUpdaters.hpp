#pragma once

#include "ofMain.h"

class ParticleUpdater
{
public:
    ParticleUpdater();

    virtual void update() = 0;
};