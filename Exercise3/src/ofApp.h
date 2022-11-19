#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Disk.h"

class ofApp : public ofBaseApp
{
public:
	ofApp();

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

	void processMouseInput();
	void spawnAttractor(int x, int y);
	void spawnDisk(int x, int y);
	void clearAttractorsPressed();
	void clearDisksPressed();

private:
	bool isMouseButtonLeftPressed = false;
	bool isGuiVisible = true;

	ofxPanel gui;
	ofxButton clearAttractors;
	ofxButton clearDisks;
	ofxFloatSlider dt;
	ofxFloatSlider attractorRadius;
	float minDiskRadius = 10.f;
	float maxDiskRadius = 30.f;
	ofxFloatSlider viscosity;

	std::vector<Disk> disks;
	std::vector<Attractor> attractors;
};