#include "ofApp.hpp"

void ofApp::setup()
{
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    ofSetCircleResolution(100);

    particleSystem.addEmitter(std::make_shared<StaticBoxEmitter>(1000, ofVec3f(0, 0, 0), ofVec3f(100, 100, 100)));
    particleSystem.addEmitter(std::make_shared<StaticSphereEmitter>(1000, ofVec3f(200, 0, 0), 100));
    particleSystem.addEmitter(std::make_shared<StaticSphereEmitter>(1000, ofVec3f(-200, 0, 0), 100));
    particleSystem.addEmitter(std::make_shared<StaticSphereEmitter>(1000, ofVec3f(0, 200, 0), 100));
    particleSystem.addEmitter(std::make_shared<StaticSphereEmitter>(1000, ofVec3f(0, -200, 0), 100));
    particleSystem.addEmitter(std::make_shared<StaticSphereEmitter>(1000, ofVec3f(0, 0, 200), 100));
    particleSystem.addEmitter(std::make_shared<StaticSphereEmitter>(1000, ofVec3f(0, 0, -200), 100));

    particleSystem.addUpdater(std::make_shared<TimeUpdater>());
}

void ofApp::update()
{
    particleSystem.update(float(ofGetLastFrameTime()));
}

void ofApp::draw()
{
    ofBackground(0);

    camera.begin();
    ofEnableDepthTest();
    particleSystem.draw();
    ofDisableDepthTest();
    camera.end();

    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapString(ofToString(particleSystem.particles.alive_count), 10, 40);
}