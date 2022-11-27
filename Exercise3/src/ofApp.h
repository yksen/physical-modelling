#pragma once

#include "Attractor.h"
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
	void windowResized(int w, int h);

	void updateDt(float &dt);
	void updateDisksAttraction(bool &disksAttractionEnabled);
	void processMouseInput();
	void spawnAttractor(int x, int y);
	void spawnDisk(int x, int y);
	void clearAttractorsPressed();
	void clearDisksPressed();
	void generateViscosity();

private:
	bool isMouseButtonLeftPressed = false;
	bool isGuiVisible = true;

	ofxPanel gui;
	ofxLabel fpsLabel;
	ofxLabel diskCountLabel;
	ofxToggle attractorsVisibilityToggle;
	ofxToggle viscosityVisibilityToggle;
	ofxButton clearAttractorsButton;
	ofxButton clearDisksButton;
	ofxButton regenerateViscosityButton;
	ofxToggle disksAttractionToggle;
	ofxFloatSlider dt;
	ofxFloatSlider attractorRadius;
	float minDiskRadius = 10.f;
	float maxDiskRadius = 30.f;

	std::vector<unique_ptr<Object>> attractors;
	std::vector<unique_ptr<Object>> disks;
	std::vector<std::vector<float>> viscosity;
	ofImage viscosityImage;
};