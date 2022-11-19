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
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

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

	std::vector<Disk> disks;
	std::vector<Attractor> attractors;
};