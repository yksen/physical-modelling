#pragma once

#include "SoftBody.hpp"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

	ofEasyCam camera;
	SoftBody softBody;
	
	ofxPanel gui;
	ofxLabel fpsLabel;
	ofxFloatSlider dampingSlider;
	ofxFloatSlider pressureSlider;
	ofxFloatSlider elasticitySlider;
};
