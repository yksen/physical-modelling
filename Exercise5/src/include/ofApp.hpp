#pragma once

#include "SoftBody.hpp"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void setupGui();
	void initializeCircle();
	void initializeRope();
	void update();
	void draw();

	void onIntegrationMethodChange(bool &value);
	void keyPressed(int key);
	void keyReleased(int key);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

	ofEasyCam camera;
	float cameraDistance{200.f};
	float screenToWorldScale{0.908378f};

	SoftBody softBody;
	ofVec2f mouseDelta;
	float clickAndDragRange{2.f};
	Point *draggedPoint;

	bool isMousePressed{false};
	bool enableGui{true};
	bool floorCollisionEnabled{true};
	bool pressureEnabled{true};

	ofxPanel gui;
	ofxLabel fpsLabel;
	ofxToggle integrationMethodToggle;
	ofxFloatSlider deltaTimeSlider;
	ofxFloatSlider dampingSlider;
	ofxFloatSlider pressureSlider;
	ofxFloatSlider elasticitySlider;
	ofxLabel debugLabel;
};
