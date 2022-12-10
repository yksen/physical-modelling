#pragma once

#include "ofMain.h"

class ParticleGenerator
{
public:
    ParticleGenerator();

    virtual void generate(size_t start_id, size_t end_id) = 0;
};