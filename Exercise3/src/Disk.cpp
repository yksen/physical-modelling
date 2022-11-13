#include "Disk.h"

Disk::Disk()
    : Disk(ofVec2f(0, 0), ofVec2f(0, 0), 0, 0)
{
}

Disk::Disk(ofVec2f position, ofVec2f velocity, float radius, float mass)
    : position(position), velocity(velocity), radius(radius), mass(mass)
{
    color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
}

void Disk::update(float dt, ofVec2f center)
{
    processAcceleration(dt, center);
    processVelocity(dt);
    checkBorderCollision();
}

void Disk::processAcceleration(float dt, ofVec2f center)
{
    ofVec2f acceleration;
    acceleration.x = (center.x - position.x) / (position.distance(center) * position.distance(center));
    acceleration.y = (center.y - position.y) / (position.distance(center) * position.distance(center));
    velocity += acceleration * dt;
}

void Disk::processVelocity(float dt)
{
    position += velocity * dt;
}

void Disk::checkBorderCollision()
{
    if (position.x - radius < 0 || position.x + radius > ofGetWidth())
    {
        velocity.x *= -1;
        position.x = ofClamp(position.x, radius, ofGetWidth() - radius);
    }

    if (position.y - radius < 0 || position.y + radius > ofGetHeight())
    {
        velocity.y *= -1;
        position.y = ofClamp(position.y, radius, ofGetHeight() - radius);
    }
}

void Disk::draw()
{
    ofSetColor(color);
    ofDrawCircle(position.x, position.y, radius);
}