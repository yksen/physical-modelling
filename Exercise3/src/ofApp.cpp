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
    regenerateViscosity.addListener(this, &ofApp::generateViscosity);
    disksAttractionEnabled.addListener(this, &ofApp::updateDisksAttraction);
    dt.addListener(this, &ofApp::updateDt);

    gui.setup();
    gui.add(areAttractorsVisible.setup("Show attractors", true));
    gui.add(isViscosityVisible.setup("Show viscosity", true));
    gui.add(clearAttractors.setup("Clear attractors"));
    gui.add(clearDisks.setup("Clear disks"));
    gui.add(regenerateViscosity.setup("Generate viscosity"));
    gui.add(disksAttractionEnabled.setup("Disks attraction", false));
    gui.add(dt.setup("dt", 1.f, -10.f, 10.f));
    gui.add(attractorRadius.setup("attractor radius", 15.f, 1.f, 100.f));

    generateViscosity();
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
    generateViscosity();
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

void ofApp::generateViscosity()
{
    ofVec2f window_size = ofGetWindowSize();

    viscosity.resize(window_size.x);
    viscosity.assign(window_size.x, std::vector<float>(window_size.y));
    viscosityImage.allocate(window_size.x, window_size.y, OF_IMAGE_COLOR);

    ofVec2f offset(ofRandom(10000), ofRandom(10000));

    for (size_t x = 0; x < viscosity.size(); ++x)
        for (size_t y = 0; y < viscosity[x].size(); ++y)
        {
            float noiseValue = ofNoise((offset.x + x) / window_size.x, (offset.y + y) / window_size.y);
            viscosity[x][y] = ofMap(noiseValue, 0.f, 1.f, 0.f, 0.0001f);
            viscosityImage.setColor(x, y, ofColor(noiseValue * 255));
        }
    viscosityImage.update();
}