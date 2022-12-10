#pragma once

#include "ofMain.h"

class ParticleData
{
public:
    ParticleData(){};

    void generate(size_t count);

    size_t count{0};
    std::vector<bool> alive;
    std::vector<ofColor> color;
    std::vector<ofVec3f> position;
    std::vector<ofVec3f> velocity;
    std::vector<ofVec3f> acceleration;
};

class ParticleGenerator
{
public:
    ParticleGenerator(){};

    virtual void generate(ParticleData *particles, size_t start_id, size_t end_id) = 0;
};

class ParticleEmitter
{
public:
    ParticleEmitter(ParticleData *particles, size_t count) : start_id(particles->count), end_id(particles->count + count){};

    virtual void emit(ParticleData *particles);
    void addGenerator(std::shared_ptr<ParticleGenerator> generator);

    size_t start_id;
    size_t end_id;
    std::vector<std::shared_ptr<ParticleGenerator>> generators;
};

class ParticleUpdater
{
public:
    ParticleUpdater(){};

    virtual void update() = 0;
};

class ParticleSystem
{
public:
    ParticleSystem(){};

    void draw();
    void update();

    void addEmitter(std::shared_ptr<ParticleEmitter> emitter);
    void addUpdater(std::shared_ptr<ParticleUpdater> updater);

    float dt;
    ParticleData particles;
    std::vector<std::shared_ptr<ParticleEmitter>> emitters;
    std::vector<std::shared_ptr<ParticleUpdater>> updaters;
};