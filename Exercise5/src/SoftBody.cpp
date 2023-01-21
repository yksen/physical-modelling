#include "SoftBody.hpp"

void Point::draw()
{
    ofSetColor(ofColor::white);
    ofDrawSphere(this->position, 1.f);
}

void Point::update(float dt)
{
    applyGravity();
    if (!this->isFixed)
        updateEuler(dt);
    this->force = ofVec3f(0, 0, 0);
}

void Point::applyGravity()
{
    this->force += gravity * this->mass;
}

void Point::updateEuler(float dt)
{
    ofVec3f acceleration = this->force / this->mass;
    this->velocity += acceleration * dt;
    this->position += this->velocity * dt;
}

void Point::updateVerlet(float dt)
{
    ofVec3f temp = this->position;
    this->position += (this->position - this->oldPosition) + this->force / this->mass * dt * dt;
    this->oldPosition = temp;
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

void Spring::update(float volume)
{
    direction = links.first->position - links.second->position;
    distance = direction.length();
    applyRestoringForce();
}

void Spring::applyRestoringForce()
{
    ofVec3f velocityDelta = links.first->velocity - links.second->velocity;

    ofVec3f restoringForce = (distance - length) * elasticity + velocityDelta * direction * damping / distance;
    restoringForce *= direction.getNormalized();

    links.first->force -= restoringForce;
    links.second->force += restoringForce;
}


void SoftBody::draw()
{
    for (auto &spring : springs)
        spring.draw();

    for (auto &point : points)
        point.draw();
}

void SoftBody::update(float dt)
{
    float volume = getVolume();

    for (auto &spring : springs)
        spring.update(volume);

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

float SoftBody::getVolume()
{
    float volume = 1.f;

    for (auto &spring : springs)
        volume += spring.distance * spring.distance;

    return volume;
}