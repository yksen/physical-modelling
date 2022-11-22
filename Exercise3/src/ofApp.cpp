#include "ofApp.h"

ofApp::ofApp()
{
}

void ofApp::setup()
{
    ofSetBackgroundColor(0);
    ofSetCircleResolution(100);
    ofSetFrameRate(144);

    Object::attractors = &attractors;
    Object::disks = &disks;
    Object::viscosity = &viscosity;

    clearAttractors.addListener(this, &ofApp::clearAttractorsPressed);
    clearDisks.addListener(this, &ofApp::clearDisksPressed);
    disksAttractionEnabled.addListener(this, &ofApp::updateDisksAttraction);
    dt.addListener(this, &ofApp::updateDt);

    gui.setup();
    gui.add(areAttractorsVisible.setup("Show attractors", true));
    gui.add(isViscosityVisible.setup("Show viscosity", true));
    gui.add(disksAttractionEnabled.setup("Disks attraction", false));
    gui.add(clearAttractors.setup("Clear attractors"));
    gui.add(clearDisks.setup("Clear disks"));
    gui.add(dt.setup("dt", 1.f, -10.f, 10.f));
    gui.add(attractorRadius.setup("attractor radius", 15.f, 1.f, 100.f));

    generateViscosity(ofGetWidth(), ofGetHeight());
}

void ofApp::update()
{
    processMouseInput();

    for (auto &attractor : attractors)
        attractor->update();
    for (auto &disk : disks)
        disk->update();
}

void ofApp::draw()
{
    if (isViscosityVisible)
    {
        ofSetColor(255);
        viscosityImage.draw(0.f, 0.f);
    }

    for (auto &disk : disks)
        disk->draw();
    if (areAttractorsVisible)
        for (auto &attractor : attractors)
            attractor->draw();

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

void ofApp::windowResized(int w, int h)
{
    generateViscosity(w, h);
}

void ofApp::updateDt(float &dt)
{
    Object::dt = dt;
}

void ofApp::updateDisksAttraction(bool &disksAttractionEnabled)
{
    Object::disksAttractionEnabled = disksAttractionEnabled;
}

void ofApp::processMouseInput()
{
    if (isMouseButtonLeftPressed)
        spawnDisk(ofGetMouseX(), ofGetMouseY());
}

void ofApp::spawnAttractor(int x, int y)
{
    attractors.push_back(make_unique<Attractor>(ofVec2f(x, y), ofVec2f(0, 0), attractorRadius, attractorRadius));
}

void ofApp::spawnDisk(int x, int y)
{
    float radius = ofRandom(minDiskRadius, maxDiskRadius);
    disks.push_back(make_unique<Disk>(ofVec2f(x, y), ofVec2f(0, 0), radius, radius));
}

void ofApp::clearAttractorsPressed()
{
    attractors.clear();
}

void ofApp::clearDisksPressed()
{
    disks.clear();
}

void ofApp::generateViscosity(int width, int height)
{
    viscosity.resize(width);
    viscosity.assign(width, std::vector<float>(height));
    viscosityImage.allocate(width, height, OF_IMAGE_COLOR);
    for (size_t x = 0; x < viscosity.size(); ++x)
        for (size_t y = 0; y < viscosity[x].size(); ++y)
        {
            float noiseValue = ofNoise(x / 10, y / 10);
            viscosity[x][y] = ofMap(noiseValue, 0.f, 1.f, 0.f, 0.0001f);
            viscosityImage.setColor(x, y, ofColor(noiseValue * 255, noiseValue * 255, noiseValue * 255));
        }
    viscosityImage.update();
}