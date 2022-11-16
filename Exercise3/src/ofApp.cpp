#include "ofApp.h"

ofApp::ofApp(size_t diskCount, float dt)
    : diskCount(diskCount), dt(dt)
{
}

void ofApp::setup()
{
    ofSetBackgroundColor(0);
    ofSetCircleResolution(100);
    ofSetFrameRate(144);

    center = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);

    for (size_t i = 0; i < diskCount; ++i)
    {
        float radius = ofRandom(minDiskRadius, maxDiskRadius);
        disks.push_back(
            Disk(
                ofVec2f(ofRandom(maxDiskRadius, ofGetWidth() - maxDiskRadius), ofRandom(maxDiskRadius, ofGetHeight() - maxDiskRadius)),
                ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1)),
                radius,
                10,
                &attractors));
    }
}

void ofApp::update()
{
    for (auto &disk : disks)
    {
        disk.update(dt);
    }
}

void ofApp::draw()
{
    for (auto &disk : disks)
    {
        disk.draw();
    }
    for (auto &attractor : attractors)
    {
        attractor.draw();
    }
}

void ofApp::keyPressed(int key)
{
}

void ofApp::keyReleased(int key)
{
}

void ofApp::mouseMoved(int x, int y)
{
}

void ofApp::mouseDragged(int x, int y, int button)
{
}

void ofApp::mousePressed(int x, int y, int button)
{
    attractors.push_back({ofVec2f(x, y), 20});
}

void ofApp::mouseReleased(int x, int y, int button)
{
}

void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
    dt += scrollY * 0.25f;
}

void ofApp::mouseEntered(int x, int y)
{
}

void ofApp::mouseExited(int x, int y)
{
}

void ofApp::windowResized(int w, int h)
{
    center = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
}

void ofApp::gotMessage(ofMessage msg)
{
}

void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
