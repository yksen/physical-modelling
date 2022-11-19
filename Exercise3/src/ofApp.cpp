#include "ofApp.h"

ofApp::ofApp()
{
}

void ofApp::setup()
{
    ofSetBackgroundColor(0);
    ofSetCircleResolution(100);
    ofSetFrameRate(144);

    clearAttractors.addListener(this, &ofApp::clearAttractorsPressed);
    clearDisks.addListener(this, &ofApp::clearDisksPressed);

    gui.setup();
    gui.add(clearAttractors.setup("Clear Attractors"));
    gui.add(clearDisks.setup("Clear Disks"));
    gui.add(dt.setup("dt", 1.f, -10.f, 10.f));
    gui.add(attractorRadius.setup("attractor radius", 15.f, 1.f, 100.f));
    gui.add(viscosity.setup("viscosity", 0.0005f, 0.f, 0.001f));
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

    if (isGuiVisible)
        gui.draw();
}

void ofApp::keyPressed(int key)
{
    if (key == 'h')
        isGuiVisible = !isGuiVisible;
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
            &attractors,
            &viscosity));
}

void ofApp::clearAttractorsPressed()
{
    attractors.clear();
}

void ofApp::clearDisksPressed()
{
    disks.clear();
}