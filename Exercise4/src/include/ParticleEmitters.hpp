#pragma once

#include "ofMain.h"
#include "ParticleGenerators.hpp"

class ParticleEmitter
{
public:
    ParticleEmitter();

    virtual void emit() = 0;

    std::vector<shared_ptr<ParticleGenerator>> generators;
};