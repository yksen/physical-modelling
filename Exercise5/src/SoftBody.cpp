#include "SoftBody.hpp"

void Point::customDraw()
{
    ofSetColor(ofColor::white);
    ofDrawSphere(this->getPosition(), 1.f);
}

void Spring::draw()
{
    ofSetColor(ofColor::red);
    ofDrawLine(links.first->getPosition(), links.second->getPosition());
}

float Spring::getLength()
{
    return glm::distance(links.first->getPosition(), links.second->getPosition());
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