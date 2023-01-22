#pragma once

#include "SoftBody.hpp"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void setupGui();
	void initializeCircle();
	void initializeSphere();
	void update();
	void draw();

	void onIntegrationMethodChange(bool &value);
	void keyPressed(int key);
	void keyReleased(int key);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

	ofEasyCam camera;
	SoftBody softBody;
	
	ofxPanel gui;
	ofxLabel fpsLabel;
	ofxFloatSlider deltaTimeSlider;
	ofxToggle integrationMethodToggle;
	ofxFloatSlider dampingSlider;
	ofxFloatSlider pressureSlider;
	ofxFloatSlider elasticitySlider;
};
