#include "ofApp.hpp"

void ofApp::setup()
{
    ofSetVerticalSync(true);
    ofSetFrameRate(144);

    setupCamera();
    setupGui();

    spawnTokens(1000ULL);
    initializeCircle();
}

void ofApp::setupCamera()
{
    camera.setTarget({0, 0, 0});
    camera.setDistance(cameraDistance);
    camera.disableMouseInput();
}

void ofApp::setupGui()
{
    gui.setup();
    gui.add(fpsLabel.setup("FPS", "0"));
    gui.add(scoreLabel.setup("Score", "0"));
    gui.add(integrationMethodToggle.setup("Verlet/Euler", false));
    gui.add(deltaTimeSlider.setup("Delta Time", 1e-2f, 1e-4f, 1e-2f));
    gui.add(dampingSlider.setup("Damping", 20.f, 0.f, 30.f));
    gui.add(elasticitySlider.setup("Elasticity", 500.f, 100.f, 5000.f));
    gui.add(pressureSlider.setup("Pressure", 1e3f, 1e2f, 1e5f));

    integrationMethodToggle.addListener(this, &ofApp::onIntegrationMethodChange);
}

void ofApp::spawnTokens(size_t count)
{
    for (size_t i = 0; i < count; ++i)
        tokenPositions.emplace_back(ofRandom(-500.f, 500.f), ofRandom(-500.f, 500.f), ofRandom(-500.f, 500.f));
}

void ofApp::initializeCircle()
{
    size_t pointCount = 20;
    float radius = 20.f;

    for (size_t i = 0; i < pointCount; ++i)
        softBody.points.emplace_back(ofVec3f(radius * sin(i * 2 * PI / pointCount), radius + radius * cos(i * 2 * PI / pointCount), 0.f));
    for (size_t i = 0; i < pointCount; ++i)
        softBody.addSpring({i, (i + 1) % pointCount});
}

void ofApp::initializeRope()
{
    size_t pointCount = 20;
    float length = 100.f;

    for (size_t i = 0; i < pointCount; ++i)
        softBody.points.emplace_back(ofVec3f(0.f, length - i * length / pointCount, 0.f));
    for (size_t i = 0; i < pointCount - 1; ++i)
        softBody.addSpring({i, i + 1});

    softBody.points.front().isFixed = true;
    boxCollisionEnabled = false;
    pressureEnabled = false;
}

void ofApp::update()
{
    Spring::damping = dampingSlider;
    Spring::elasticity = elasticitySlider;
    Spring::pressure = pressureSlider;
    Spring::pressureEnabled = pressureEnabled;

    if (draggedPoint != nullptr)
    {
        auto mousePosition = camera.screenToWorld({mouseX, mouseY, screenToWorldScale});
        draggedPoint->position = {mousePosition.x, mousePosition.y, 0.f};
    }

    softBody.update(deltaTimeSlider);
    if (boxCollisionEnabled)
        softBody.collideWithBox();

    ofVec3f softBodyCenter = softBody.getAveragePosition();
    camera.setTarget(softBodyCenter);
    camera.setPosition(softBodyCenter + ofVec3f(0.f, 0.f, cameraDistance));

    std::vector<size_t> indicesToRemove;
    for (size_t i = 0; i < tokenPositions.size(); ++i)
        if (ofVec2f(tokenPositions[i].x, tokenPositions[i].y).distance(ofVec2f(softBodyCenter.x, softBodyCenter.y)) < 50.f)
        {
            ++score;
            scoreLabel = ofToString(score);
            indicesToRemove.push_back(i);
        }
    for (auto it = indicesToRemove.rbegin(); it != indicesToRemove.rend(); ++it)
        tokenPositions.erase(tokenPositions.begin() + *it);

    fpsLabel = ofToString(ofGetFrameRate());
}

void ofApp::draw()
{
    ofBackground(ofColor::black);

    camera.begin();
    ofEnableDepthTest();

    softBody.draw();
    ofDrawGrid(100.f, 5, false, false, false, true);
    for (auto &tokenPosition : tokenPositions)
    {
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofDrawSphere(tokenPosition, 5.f);
    }
    if (isMousePressed && draggedPoint == nullptr)
    {
        ofSetColor(ofColor::limeGreen);
        ofDrawLine(worldMousePosition, camera.screenToWorld({mouseX, mouseY, screenToWorldScale}));
    }

    ofDisableDepthTest();
    camera.end();

    gui.draw();
}

void ofApp::onIntegrationMethodChange(bool &value)
{
    Point::integrate = value ? &Point::integrateEuler : &Point::integrateVerlet;
}

void ofApp::keyPressed(int key)
{
}

void ofApp::keyReleased(int key)
{
    switch (key)
    {
    case OF_KEY_ESC:
        ofExit();
        break;
    }
}

void ofApp::mousePressed(int x, int y, int button)
{
    isMousePressed = true;
    mouseDelta = ofVec3f(x, y, 0.f);
    worldMousePosition = camera.screenToWorld({x, y, screenToWorldScale});

    for (auto &point : softBody.points)
        if (point.position.distance(camera.screenToWorld({x, y, screenToWorldScale})) < clickAndDragRange)
            draggedPoint = &point;
}

void ofApp::mouseReleased(int x, int y, int button)
{
    isMousePressed = false;
    mouseDelta -= ofVec3f(x, y, 0.f);

    if (draggedPoint != nullptr)
        draggedPoint = nullptr;
    else
        for (auto &point : softBody.points)
            point.force += ofVec3f(mouseDelta.x, -mouseDelta.y, 0.f) * 50.f;
}