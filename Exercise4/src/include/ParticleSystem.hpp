#pragma once

#include "ofMain.h"

class ParticleData
{
public:
    size_t count{0};

    std::unique_ptr<std::vector<bool>> alive;
    std::unique_ptr<std::vector<ofColor>> color;
    std::unique_ptr<std::vector<ofVec3f>> position;
    std::unique_ptr<std::vector<ofVec3f>> velocity;
    std::unique_ptr<std::vector<ofVec3f>> acceleration;
};

class ParticleGenerator
{
public:
    ParticleGenerator(){};

    virtual void generate(size_t start_id, size_t end_id) = 0;
};

class ParticleEmitter
{
public:
    ParticleEmitter(size_t count, ParticleData *particles);

    virtual void emit();
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