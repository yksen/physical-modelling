#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class Object
{
public:
    static const float MIN_ATTRACTION_DISTANCE;

    Object(ofVec2f position, ofVec2f velocity, float radius, float mass);

    virtual void update();
    virtual void draw();

    void attract(Object *other);
    void checkBorderCollision();
    void applyVelocity();

    static float dt;
    static std::vector<unique_ptr<Object>> *attractors;
    static std::vector<unique_ptr<Object>> *disks;
    static std::vector<std::vector<float>> *viscosity;

    ofVec2f position;
    ofVec2f velocity;
    float radius;
    float mass;
    ofColor color;
};