#include "Disk.h"

void Attractor::draw()
{
    ofSetColor(ofColor::yellow);
    ofDrawCircle(position, radius);
}

Disk::Disk()
    : Disk(ofVec2f(0, 0), ofVec2f(0, 0), 0, 0, nullptr)
{
}

Disk::Disk(ofVec2f position, ofVec2f velocity, float radius, float mass, std::vector<Attractor> *attractors)
    : position(position), velocity(velocity), radius(radius), mass(mass), attractors(attractors)
{
    color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
}

void Disk::update(float dt)
{
    processAcceleration(dt);
    processVelocity(dt);
    checkBorderCollision();
}

void Disk::processAcceleration(float dt)
{
    ofVec2f acceleration = {0, 0};
    for (size_t i = 0; i < attractors->size(); ++i)
    {
        ofVec2f direction = attractors->at(i).position - position;
        float distance = direction.length();
        if (distance < MIN_ATTRACTION_DISTANCE)
            continue;
        float force = (attractors->at(i).mass) / (distance * distance);
        acceleration += direction.normalize() * force;
    }
    velocity += acceleration * dt;
}

void Disk::processVelocity(float dt)
{
    position += velocity * dt;
}

void Disk::checkBorderCollision()
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

void Disk::draw()
{
    ofSetColor(color);
    ofDrawCircle(position.x, position.y, radius);
}