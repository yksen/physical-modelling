#include "ofApp.hpp"

void ofApp::setup()
{
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    ofSetCircleResolution(100);

    particleSystem = ParticleSystem();

    particleSystem.addEmitter(std::make_shared<ParticleEmitter>(&particleSystem.particles, 100));
    particleSystem.emitters[0]->addGenerator(std::make_shared<BoxPositionGenerator>(ofVec3f(0, 0, 0), ofVec3f(100, 100, 100)));

    particleSystem.addEmitter(std::make_shared<ParticleEmitter>(&particleSystem.particles, 100));
    particleSystem.emitters[1]->addGenerator(std::make_shared<SpherePositionGenerator>(ofVec3f(0, 200, 0), 100));
}

void ofApp::update()
{
    particleSystem.update(ofGetLastFrameTime());
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
}

void ofApp::keyPressed(int key)
{
}

void ofApp::keyReleased(int key)
{
}

void ofApp::windowResized(int w, int h)
{
}