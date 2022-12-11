#pragma once

#include "ParticleSystem.hpp"

class FloorUpdater : public ParticleUpdater
{
public:
    FloorUpdater(float floor_level = 0.0f) : floor_level(floor_level){};

    void update(ParticleData *particles, float dt) override;

    float floor_level;
};

class GravityUpdater : public ParticleUpdater
{
public:
    GravityUpdater(ofVec3f gravity = ofVec3f(0, -9.81f, 0)) : gravity(gravity){};

    void update(ParticleData *particles, float dt) override;

    ofVec3f gravity;
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

class TimeColorUpdater : public ParticleUpdater
{
public:
    void update(ParticleData *particles, float dt) override;

    ofColor min_color;
    ofColor max_color;
};