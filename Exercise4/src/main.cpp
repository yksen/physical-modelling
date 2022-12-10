#include "ofMain.h"
#include "ofApp.hpp"

int main()
{
	ofGLWindowSettings settings;
	settings.windowMode = OF_FULLSCREEN;

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();
}
