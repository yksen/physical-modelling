#include "ofMain.h"
#include "ofApp.h"

int main(int argc, char **argv)
{
	size_t diskCount = 10;
	if (argc > 1)
		diskCount = std::stoull(argv[1]);
		
	ofGLWindowSettings settings;
	settings.setSize(1024, 768);
	settings.windowMode = OF_WINDOW;

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>(diskCount));
	ofRunMainLoop();
}
