#include "SoftBody.hpp"

void Point::draw()
{
    ofSetColor(ofColor::white);
    ofDrawSphere(this->position, 1.f);
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