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

    for (size_t i = 0; i < diskCount; ++i)
    {
        disks.push_back(
            Disk(
                ofRandom(maxDiskRadius, ofGetWidth() - maxDiskRadius),
                ofRandom(maxDiskRadius, ofGetHeight() - maxDiskRadius),
                ofRandom(-1, 1),
                ofRandom(-1, 1),
                ofRandom(minDiskRadius, maxDiskRadius),
                ofRandom(1, 10)));
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
}

void ofApp::mouseReleased(int x, int y, int button)
{
}

void ofApp::mouseEntered(int x, int y)
{
}

void ofApp::mouseExited(int x, int y)
{
}

void ofApp::windowResized(int w, int h)
{
}

void ofApp::gotMessage(ofMessage msg)
{
}

void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
