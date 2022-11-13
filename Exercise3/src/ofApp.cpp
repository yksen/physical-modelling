#include "ofApp.h"

void ofApp::setup()
{
    ofSetBackgroundColor(0);
    ofSetCircleResolution(100);
    ofSetFrameRate(144);

    for (size_t i = 0; i < _diskCount; ++i)
    {
        _disks.push_back(
            Disk(
                ofRandom(_maxDiskRadius, ofGetWidth() - _maxDiskRadius),
                ofRandom(_maxDiskRadius, ofGetHeight() - _maxDiskRadius),
                ofRandom(_minDiskRadius, _maxDiskRadius),
                ofRandom(1, 10)));
    }
}

void ofApp::update()
{
}

void ofApp::draw()
{
    for (auto &disk : _disks)
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
