#include "Attractor.h"

const float Attractor::ATTRACTOR_BORDER_SIZE = 2;

void Attractor::update()
{
    for (auto &disk : *disks)
        attract(disk.get());
}

void Attractor::draw()
{
    ofSetColor(ofColor::orange);
    ofDrawCircle(position, radius);
    ofSetColor(ofColor::yellow);
    ofDrawCircle(position, radius - ATTRACTOR_BORDER_SIZE);
}