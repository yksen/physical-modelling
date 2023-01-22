#include "ofApp.hpp"

void ofApp::setup()
{
    ofSetFrameRate(144);
    camera.setDistance(100);

    gui.setup();
    gui.add(fpsLabel.setup("FPS", "0"));
    gui.add(dampingSlider.setup("Damping", 30.f, 0.f, 50.f));
    gui.add(elasticitySlider.setup("Elasticity", 1000.f, 0.f, 10000.f));
    gui.add(pressureSlider.setup("Pressure", 10000.f, 1000.f, 100000.f));

    size_t pointCount = 20;
    float radius = 20.f;

    for (size_t i = 0; i < pointCount; ++i)
        softBody.points.emplace_back(ofVec3f(radius * sin(i * 2 * PI / pointCount), radius + radius * cos(i * 2 * PI / pointCount), 0.f));
    for (size_t i = 0; i < pointCount; ++i)
        softBody.addSpring({i, (i + 1) % pointCount});
}

void ofApp::update()
{
    Spring::damping = dampingSlider;
    Spring::elasticity = elasticitySlider;
    Spring::pressure = pressureSlider;

    softBody.update(ofGetLastFrameTime());
    fpsLabel = ofToString(ofGetFrameRate());
}

void ofApp::draw()
{
    ofBackground(ofColor::black);

    camera.begin();
    ofEnableDepthTest();
    softBody.draw();
    ofDisableDepthTest();
    camera.end();

    gui.draw();
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