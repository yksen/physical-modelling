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

void SoftBody::addSpring(PointsPair links, float length)
{
    springs.push_back(Spring(links, length));
}

void SoftBody::addSpring(std::pair<size_t, size_t> indices, float length)
{
    addSpring(PointsPair(&points[indices.first], &points[indices.second]), length);
}

void SoftBody::draw()
{
    for (auto &spring : springs)
        spring.draw();

    for (auto &point : points)
        point.draw();
}