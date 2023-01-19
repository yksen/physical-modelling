#include "ofMain.h"

class Point : public ofNode
{
public:
    Point(ofVec3f position) { setPosition(position); };

    void draw() { customDraw(); };
    void customDraw() override;

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
    void addSpring(PointsPair links);
    void addSpring(std::pair<size_t, size_t> indices);

    std::vector<Point> points;
    std::vector<Spring> springs;
};