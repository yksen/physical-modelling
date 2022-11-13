#pragma once

#include "ofMain.h"

class Disk
{
public:
    Disk();
    Disk(ofVec2f position, ofVec2f velocity, float radius, float mass);

    void update(float dt, ofVec2f center);
    void draw();

    void processAcceleration(float dt, ofVec2f center);
    void processVelocity(float dt);
    void checkBorderCollision();

private:
    ofVec2f position;
    ofVec2f velocity;
    float radius;
    float mass;
    ofColor color;
};