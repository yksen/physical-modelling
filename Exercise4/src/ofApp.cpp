#include "ofApp.hpp"

void ofApp::setup()
{
    ofSetVerticalSync(true);
    ofSetCircleResolution(100);

    size_t emit_rate = 1000;
    float explosion_power = 10;

    particle_system.addEmitter(std::make_shared<SnowfallEmitter>(
        emit_rate, ofVec3f(0, 300, 0), 100));
    particle_system.addEmitter(std::make_shared<FireEmitter>(
        emit_rate, ofVec3f(0, 0, 0), 5));

    // particle_system.addEmitter(std::make_shared<ExplosionEmitter>(
    //     emit_rate, ofVec3f(-50, 0, 0), explosion_power, ofColor(255, 0, 0), ofColor(255, 255, 0)));
    // particle_system.addEmitter(std::make_shared<ExplosionEmitter>(
    //     emit_rate, ofVec3f(50, 0, 0), explosion_power, ofColor(0, 0, 255), ofColor(0, 255, 255)));

    particle_system.addUpdater(std::make_shared<GravityUpdater>());
    particle_system.addUpdater(std::make_shared<EulerUpdater>());
    particle_system.addUpdater(std::make_shared<FloorUpdater>());
    particle_system.addUpdater(std::make_shared<TimeUpdater>());
    particle_system.addUpdater(std::make_shared<TimeColorUpdater>());
}

void ofApp::update()
{
    particle_system.update(float(ofGetLastFrameTime()));
}

void ofApp::draw()
{
    ofBackground(0);

    camera.begin();
    ofEnableDepthTest();
    particle_system.draw();
    ofDisableDepthTest();
    camera.end();

    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapString(ofToString(particle_system.particles.alive_count), 10, 40);
}