#include "ofApp.hpp"

void ofApp::setup()
{
    camera.setDistance(100);

    softBody.points.resize(2);
    softBody.points[0].setPosition(0, 10.f, 0);
    softBody.addSpring({0, 1}, 10.f);
}

void ofApp::update()
{
}

void ofApp::draw()
{
    ofBackground(ofColor::black);

    camera.begin();
    ofEnableDepthTest();
    softBody.draw();
    ofDisableDepthTest();
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