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

void Disk::update()
{
    _color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
}

void Disk::draw()
{
    ofSetColor(color);
    ofDrawCircle(x, y, radius);
}