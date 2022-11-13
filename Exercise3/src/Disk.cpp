#include "Disk.h"

Disk::Disk() : Disk(0, 0, 0, 0)
{
}

Disk::Disk(float x, float y, float radius, float mass) : _x(x), _y(y), _radius(radius), _mass(mass)
{
    _color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
}

void Disk::draw()
{
    ofSetColor(_color);
    ofDrawCircle(_x, _y, _radius);
}