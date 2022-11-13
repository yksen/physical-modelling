#include "ofMain.h"
#include "ofApp.h"

int main(int argc, char **argv)
{
	size_t diskCount = 10;
	float dt = 1;
	if (argc > 2)
	{
		diskCount = std::stoull(argv[1]);
		dt = std::stof(argv[2]);
	}

	ofGLWindowSettings settings;
	settings.setSize(1024, 768);
	settings.windowMode = OF_WINDOW;

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>(diskCount, dt));
	ofRunMainLoop();
}
