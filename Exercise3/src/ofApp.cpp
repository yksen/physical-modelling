#include "ofApp.h"

ofApp::ofApp()
{
}

void ofApp::setup()
{
    ofSetBackgroundColor(0);
    ofSetCircleResolution(100);
    ofSetFrameRate(144);

    gui.setup();
    gui.add(dt.setup("dt", 1.f, -10.f, 10.f));
    gui.add(attractorRadius.setup("attractor radius", 15.f, 1.f, 100.f));
}

void ofApp::update()
{
    processMouseInput();

    for (auto &disk : disks)
        disk.update(dt);
}

void ofApp::draw()
{
    for (auto &disk : disks)
        disk.draw();
    for (auto &attractor : attractors)
        attractor.draw();

    gui.draw();
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
    if (button == OF_MOUSE_BUTTON_LEFT)
        isMouseButtonLeftPressed = true;
    else if (button == OF_MOUSE_BUTTON_RIGHT)
        spawnAttractor(x, y);
}

void ofApp::mouseReleased(int x, int y, int button)
{
    if (button == OF_MOUSE_BUTTON_LEFT)
        isMouseButtonLeftPressed = false;
}

void ofApp::windowResized(int w, int h)
{
}

void ofApp::processMouseInput()
{
    if (isMouseButtonLeftPressed)
        spawnDisk(ofGetMouseX(), ofGetMouseY());
}

void ofApp::spawnAttractor(int x, int y)
{
    attractors.push_back({ofVec2f(x, y), attractorRadius, attractorRadius});
}

void ofApp::spawnDisk(int x, int y)
{
    float radius = ofRandom(minDiskRadius, maxDiskRadius);
    disks.push_back(
        Disk(
            ofVec2f(x, y),
            ofVec2f(0, 0),
            radius,
            radius,
            &attractors));
}