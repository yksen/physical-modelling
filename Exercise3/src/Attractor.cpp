#include "Attractor.h"

void Attractor::update()
{
    for (auto &disk : *disks)
    {
        attract(disk.get());
    }
}

void Attractor::draw()
{
    ofSetColor(ofColor::yellow);
    ofDrawCircle(position, radius);
}