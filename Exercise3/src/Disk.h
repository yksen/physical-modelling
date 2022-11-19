#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
    Disk(ofVec2f position, ofVec2f velocity, float radius, float mass, std::vector<Attractor> *attractors, ofxFloatSlider *viscosity);

    void update(float dt);
    void draw();

    void processVelocity(float dt);
    void processAcceleration(float dt);
    ofVec2f calculateGravitation();
    ofVec2f calculateDrag();
    void checkBorderCollision();

private:
    const float MIN_ATTRACTION_DISTANCE = 10;

    ofVec2f position;
    ofVec2f velocity;
    float radius;
    float mass;
    ofColor color;
    std::vector<Attractor> *attractors;
    ofxFloatSlider *viscosity;
};