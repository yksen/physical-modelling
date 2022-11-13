#include "Disk.h"

Disk::Disk()
    : Disk(0, 0, 0, 0, 0, 0)
{
}

Disk::Disk(float x, float y, float vx, float vy, float radius, float mass)
    : x(x), y(y), vx(vx), vy(vy), radius(radius), mass(mass)
{
    color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
}

void Disk::update(float dt)
{
    x += vx * dt;
    y += vy * dt;

    if (x - radius < 0 || x + radius > ofGetWidth())
        vx *= -1;

    if (y - radius < 0 || y + radius > ofGetHeight())
        vy *= -1;
}

void Disk::draw()
{
    ofSetColor(color);
    ofDrawCircle(x, y, radius);
}