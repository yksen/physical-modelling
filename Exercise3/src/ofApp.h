#pragma once

#include "ofMain.h"
#include "Disk.h"

class ofApp : public ofBaseApp
{
public:
	ofApp(size_t diskCount, float dt);

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	float dt;
	ofVec2f center;

	size_t diskCount;
	std::vector<Disk> disks;

	float minDiskRadius = 10;
	float maxDiskRadius = 50;
};