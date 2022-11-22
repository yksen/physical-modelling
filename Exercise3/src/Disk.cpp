#include "Disk.h"

void Disk::update()
{
    checkBorderCollision();
    applyDrag();
    applyVelocity();
}

void Disk::applyDrag()
{
    ofVec2f drag = -6 * PI * velocity * radius * viscosity->at(position.x).at(position.y);
    ofVec2f acceleration = drag / mass;
    velocity += acceleration * dt;
}