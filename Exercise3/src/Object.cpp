#include "Object.h"

const float Object::MIN_ATTRACTION_DISTANCE = 10;

float Object::dt = 0;
bool Object::disksAttractionEnabled = false;
std::vector<unique_ptr<Object>> *Object::attractors = nullptr;
std::vector<unique_ptr<Object>> *Object::disks = nullptr;
std::vector<std::vector<float>> *Object::viscosity = nullptr;

Object::Object(ofVec2f position, ofVec2f velocity, float radius, float mass)
{
    this->position = position;
    this->velocity = velocity;
    this->radius = radius;
    this->mass = mass;
    color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
}

void Object::update()
{
}

void Object::draw()
{
    ofSetColor(color);
    ofDrawCircle(position.x, position.y, radius);
}

void Object::attract(Object *other)
{
    ofVec2f direction = position - other->position;
    float distance = direction.length();
    if (distance < MIN_ATTRACTION_DISTANCE)
        return;
    float force = (mass * other->mass) / (distance * distance);
    ofVec2f acceleration = direction.normalize() * force / mass;
    other->velocity += acceleration * dt;
}

void Object::checkBorderCollision()
{
    if (position.x - radius < 0 || position.x + radius > ofGetWidth())
    {
        velocity.x *= -1;
        position.x = ofClamp(position.x, radius, ofGetWidth() - radius);
    }

    if (position.y - radius < 0 || position.y + radius > ofGetHeight())
    {
        velocity.y *= -1;
        position.y = ofClamp(position.y, radius, ofGetHeight() - radius);
    }
}

void Object::applyVelocity()
{
    position += velocity * dt;
}