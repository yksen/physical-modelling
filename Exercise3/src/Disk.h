#pragma once

#include "ofMain.h"

class Disk
{
public:
    Disk();
    Disk(float x, float y, float vx, float vy, float radius, float mass);

    void update();
    void draw();

private:
    float x;
    float y;
    float vx;
    float vy;
    float radius;
    float mass;
    ofColor color;
};