#include "ofMain.h"
#include "ofApp.hpp"

int main()
{
	ofGLWindowSettings settings;
	settings.windowMode = ofWindowMode::OF_GAME_MODE;

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();
}
