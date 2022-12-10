#pragma once

#include "ParticleSystem.hpp"
#include "ParticleGenerators.hpp"
#include "ParticleUpdaters.hpp"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void windowResized(int w, int h);

	ofEasyCam camera;
	ParticleSystem particleSystem{1000};
};
