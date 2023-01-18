#include "ofMain.h"

class Point : public ofNode
{
public:
    Point() : ofNode(){};

    void draw() { customDraw(); };
    void customDraw() override;

    ofVec3f velocity;
    ofVec3f force;
};

using PointsPair = std::pair<std::shared_ptr<Point>, std::shared_ptr<Point>>;

class Spring
{
public:
    Spring(PointsPair links, float length) : links(links), length(length){};

    void draw();

    PointsPair links;
    float length;
};

class SoftBody
{
public:
    SoftBody(){};

    void draw();
    void addSpring(PointsPair links, float length);
    void addSpring(std::pair<size_t, size_t> indices, float length);

    std::vector<Point> points;
    std::vector<Spring> springs;
};