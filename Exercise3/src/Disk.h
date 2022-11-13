#pragma once

#include "ofMain.h"

class Disk
{
public:
    Disk();
    Disk(float x, float y, float radius, float mass);

    void update();
    void draw();

private:
    float _x;
    float _y;
    float _radius;
    float _mass;
    ofColor _color;
};