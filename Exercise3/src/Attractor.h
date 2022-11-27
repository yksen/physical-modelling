#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Object.h"

class Attractor : public Object
{
public:
    static const float ATTRACTOR_BORDER_SIZE;

    using Object::Object;

    void update() override;
    void draw() override;
};