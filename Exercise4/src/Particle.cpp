#include "Particle.hpp"

Particle::Particle()
{
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    position = ofVec3f(ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2), ofRandom(-ofGetHeight() / 2, ofGetHeight() / 2), ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2));
    radius = ofRandom(1, 10);
}

void Particle::update()
{
}

void Particle::draw()
{
    ofSetColor(color);
    ofDrawSphere(position, radius);
}
