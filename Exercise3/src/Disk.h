#pragma once

#include "ofMain.h"

struct Attractor
{
    ofVec2f position;
    float radius;
    float mass;

    void draw();
};

class Disk
{
public:
    Disk();
    Disk(ofVec2f position, ofVec2f velocity, float radius, float mass, std::vector<Attractor> *attractors);

    void update(float dt);
    void draw();

    void processAcceleration(float dt);
    void processVelocity(float dt);
    void checkBorderCollision();

private:
    const float MIN_ATTRACTION_DISTANCE = 10;

    ofVec2f position;
    ofVec2f velocity;
    float radius;
    float mass;
    ofColor color;
    std::vector<Attractor> *attractors;
};