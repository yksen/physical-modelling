#include "ofApp.hpp"

void ofApp::setup()
{
}

void ofApp::update()
{
}

void ofApp::draw()
{
    camera.begin();
    ofDrawAxis(100);
    camera.end();

    ofDrawBitmapString(ofToString(ofGetFrameRate()), 0, 10);
}

void ofApp::keyPressed(int key)
{
}

void ofApp::keyReleased(int key)
{
}

void ofApp::mousePressed(int x, int y, int button)
{
}

void ofApp::mouseReleased(int x, int y, int button)
{
}