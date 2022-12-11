#pragma once

#include "ParticleSystem.hpp"
#include "ParticleEmitters.hpp"
#include "ParticleGenerators.hpp"
#include "ParticleUpdaters.hpp"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
	
	ofEasyCam camera;
	ParticleSystem particleSystem{10000};
};
