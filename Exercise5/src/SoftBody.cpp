#include "SoftBody.hpp"

void Point::draw()
{
    ofSetColor(ofColor::white);
    ofDrawSphere(this->position, 1.f);
}

void Point::update(float dt)
{
    applyGravity();

    ofVec3f acceleration = this->force / this->mass;
    this->velocity += acceleration * dt;
    this->position += this->velocity * dt;
    this->force = ofVec3f(0.f, 0.f, 0.f);

    checkFloorCollision();
}

void Point::applyGravity()
{
    this->force += gravity * this->mass;
}

void Point::checkFloorCollision()
{
    if (this->position.y < 0.f)
    {
        this->position.y = 0.f;
        this->velocity.y = 0.f;
    }
}

void Spring::draw()
{
    ofSetColor(ofColor::red);
    ofDrawLine(links.first->position, links.second->position);
}

float Spring::getLength()
{
    return links.first->position.distance(links.second->position);
}

void SoftBody::update(float dt)
{
    for (auto &point : points)
        point.update(dt);
}

void SoftBody::addSpring(PointsPair links)
{
    springs.emplace_back(links);
}

void SoftBody::addSpring(std::pair<size_t, size_t> indices)
{
    addSpring(PointsPair(&points[indices.first], &points[indices.second]));
}

void SoftBody::draw()
{
    for (auto &spring : springs)
        spring.draw();

    for (auto &point : points)
        point.draw();
}