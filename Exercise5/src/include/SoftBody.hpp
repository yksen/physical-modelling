#include "ofMain.h"

static const ofVec3f gravity{0.f, -9.81f, 0.f};

class Point
{
public:
    Point(ofVec3f position) : position(position){};

    void draw();
    void update(float dt);
    void applyGravity();
    void checkFloorCollision();

    float mass{1.f};
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
    float getLength();

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