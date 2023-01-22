#include "ofMain.h"
#include "ofxGui.h"

static const ofVec3f gravity{0.f, -9.81f, 0.f};

class Point
{
public:
    Point(ofVec3f position) : oldPosition(position), position(position){};

    void draw();
    void update(float dt);
    void applyGravity();
    void integrateEuler(float dt);
    void integrateVerlet(float dt);
    void applyFloorCollision();

    static std::function<void(Point *, float)> integrate;
    bool isFixed{false};
    float mass{1.f};
    ofVec3f oldPosition;
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f force;
};

using PointsPair = std::pair<std::shared_ptr<Point>, std::shared_ptr<Point>>;

class Spring
{
public:
    Spring(PointsPair links) : links(links), length(links.first->position.distance(links.second->position)){};

    void draw();
    void update(float volume);
    void applyRestoringForce();
    void applyPressure(float volume);

    static float damping;
    static float elasticity;
    static float pressure;
    static bool pressureEnabled;

    PointsPair links;
    ofVec3f direction;
    float distance;
    float length{10.f};
};

class SoftBody
{
public:
    void draw();
    void update(float dt);
    void addSpring(PointsPair links);
    void addSpring(std::pair<size_t, size_t> indices);
    void collideWithFloor();
    float getVolume();
    ofVec3f getAveragePosition();

    std::vector<Point> points;
    std::vector<Spring> springs;
};