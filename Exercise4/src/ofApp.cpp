#include "ofApp.hpp"

void ofApp::setup()
{
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    ofSetCircleResolution(100);

    particleSystem = ParticleSystem(1000);
}

void ofApp::update()
{
    particleSystem.update();
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