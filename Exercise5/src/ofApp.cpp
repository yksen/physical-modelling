#include "ofApp.hpp"

void ofApp::setup()
{
    gui.setup();
    gui.add(fpsLabel.setup("FPS", "0"));
    gui.add(dampingSlider.setup("Damping", 30.f, 0.f, 50.f));
    gui.add(pressureSlider.setup("Pressure", 1000.f, 0.f, 10000.f));
    gui.add(elasticitySlider.setup("Elasticity", 1000.f, 0.f, 10000.f));

    camera.setDistance(100);

    const size_t pointsCount = 20;
    float radius = 20.f;

    for (size_t i = 0; i < pointsCount; ++i)
        softBody.points.emplace_back(ofVec3f(radius * sin(i * 2 * PI / pointsCount), radius + radius * cos(i * 2 * PI / pointsCount), 0.f));
    for (size_t i = 0; i < pointsCount; ++i)
        softBody.addSpring({i, (i + 1) % pointsCount});

    softBody.points.front().isFixed = true;
}

void ofApp::update()
{
    damping = dampingSlider;
    pressure = pressureSlider;
    elasticity = elasticitySlider;
    
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