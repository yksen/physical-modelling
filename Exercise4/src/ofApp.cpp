#include "ofApp.hpp"

void ofApp::setup()
{
    ofSetVerticalSync(true);
    ofSetCircleResolution(100);

    particle_system.addEmitter(std::make_shared<ExplosionEmitter>(
        500, ofVec3f(-50, 50, -50), 75, ofColor(0), ofColor(255)));
    particle_system.addEmitter(std::make_shared<ExplosionEmitter>(
        500, ofVec3f(-50, 75, 50), 75, ofColor(0), ofColor(255)));
    particle_system.addEmitter(std::make_shared<ExplosionEmitter>(
        500, ofVec3f(50, 100, 50), 75, ofColor(0), ofColor(255)));
    particle_system.addEmitter(std::make_shared<ExplosionEmitter>(
        500, ofVec3f(50, 125, -50), 75, ofColor(0), ofColor(255)));
    particle_system.addEmitter(std::make_shared<FireEmitter>(
        750, ofVec3f(0, 0, 0), 5));
    particle_system.addEmitter(std::make_shared<SnowfallEmitter>(
        1000, ofVec3f(0, 300, 0), 100));

    particle_system.addUpdater(std::make_shared<GravityUpdater>());
    particle_system.addUpdater(std::make_shared<EulerUpdater>());
    particle_system.addUpdater(std::make_shared<FloorUpdater>());
    particle_system.addUpdater(std::make_shared<TimeUpdater>());
    particle_system.addUpdater(std::make_shared<TimeColorUpdater>());
}

void ofApp::update()
{
    particle_system.update(float(ofGetLastFrameTime()));
}

void ofApp::draw()
{
    ofBackground(0);

    camera.begin();
    ofEnableDepthTest();
    particle_system.draw();
    ofDisableDepthTest();
    camera.end();

    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapString(ofToString(particle_system.particles.alive_count), 10, 40);
}