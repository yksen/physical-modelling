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
	
	ofTime time;
	ofEasyCam camera;
	ParticleSystem particle_system{10000};
};
