#pragma once

#include "ParticleGenerators.hpp"

class StaticBoxEmitter : public ParticleEmitter
{
public:
    StaticBoxEmitter(float emit_rate, ofVec3f origin, ofVec3f range);
};

class StaticSphereEmitter : public ParticleEmitter
{
public:
    StaticSphereEmitter(float emit_rate, ofVec3f origin, float radius);
};

class ExplosionEmitter : public ParticleEmitter
{
public:
    ExplosionEmitter(float emit_rate, ofVec3f origin, float power, ofColor min_color, ofColor max_color);
};

class SnowfallEmitter : public ParticleEmitter
{
public:
    SnowfallEmitter(float emit_rate, ofVec3f origin, float radius);
};

class FireEmitter : public ParticleEmitter
{
public:
    FireEmitter(float emit_rate, ofVec3f origin, float radius);
};