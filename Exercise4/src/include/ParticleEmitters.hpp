#pragma once

#include "ParticleGenerators.hpp"

class StaticBoxEmitter : public ParticleEmitter
{
public:
    StaticBoxEmitter(float emit_rate, ofVec3f origin, ofVec3f range) : ParticleEmitter(emit_rate)
    {
        addGenerator(std::make_shared<TimeGenerator>());
        addGenerator(std::make_shared<RandomColorGenerator>());
        addGenerator(std::make_shared<BoxPositionGenerator>(origin, range));
    };
};

class StaticSphereEmitter : public ParticleEmitter
{
public:
    StaticSphereEmitter(float emit_rate, ofVec3f origin, float radius) : ParticleEmitter(emit_rate)
    {
        addGenerator(std::make_shared<TimeGenerator>());
        addGenerator(std::make_shared<RandomColorGenerator>());
        addGenerator(std::make_shared<SpherePositionGenerator>(origin, radius));
    };
};