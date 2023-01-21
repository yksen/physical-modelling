#include "ofMain.h"
#include "ofxGui.h"

static const ofVec3f gravity{0.f, -9.81f, 0.f};
static float damping{30.f};
static float elasticity{1000.f};
static float pressure{1000.f};

class Point
{
public:
    Point(ofVec3f position) : position(position), oldPosition(position){};

    void draw();
    void update(float dt);
    void applyGravity();
    void updateVerlet(float dt);
    void checkFloorCollision();

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
    Spring(PointsPair links) : links(links){};

    void draw();
    void update();

    float length{1.f};
    PointsPair links;
};

class SoftBody
{
public:
    void draw();
    void update(float dt);
    void addSpring(PointsPair links);
    void addSpring(std::pair<size_t, size_t> indices);

    std::vector<Point> points;
    std::vector<Spring> springs;
};