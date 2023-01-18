#include "ofApp.hpp"

void ofApp::setup()
{
    camera.setDistance(100);

    const size_t pointsCount = 30;
    float radius = 20.f;

    for (size_t i = 0; i < pointsCount; ++i)
        softBody.points.emplace_back(ofVec3f(radius * sin(i * 2 * PI / pointsCount), radius * cos(i * 2 * PI / pointsCount), 0.f));
    for (size_t i = 0; i < pointsCount; ++i)
        softBody.addSpring({i, (i + 1) % pointsCount}, 10.f);
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