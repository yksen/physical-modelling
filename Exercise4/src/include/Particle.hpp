#pragma once

#include "ofMain.h"

class Particle
{
public:
    Particle();

    void update();
    void draw();
    
    ofColor color;
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f acceleration;
    float radius;
    float lifespan;
};