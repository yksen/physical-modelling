#include "ofApp.h"

ofApp::ofApp()
{
}

void ofApp::setup()
{
    ofSetBackgroundColor(0);
    ofSetCircleResolution(100);
    ofSetFrameRate(144);
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
    switch (button)
    {
    case ofKey::OF_MOUSE_BUTTON_LEFT:
        [this, x, y]
        {
            float radius = ofRandom(minDiskRadius, maxDiskRadius);
            disks.push_back(
                Disk(
                    ofVec2f(x, y),
                    ofVec2f(0, 0),
                    radius,
                    radius,
                    &attractors));
        }();
        break;
    case ofKey::OF_MOUSE_BUTTON_RIGHT:
        attractors.push_back({ofVec2f(x, y), attractorRadius, attractorRadius});
        break;
    }
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
}

void ofApp::gotMessage(ofMessage msg)
{
}

void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
