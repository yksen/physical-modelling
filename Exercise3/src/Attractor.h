#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Object.h"

class Attractor : public Object
{
public:
    using Object::Object;

    void update() override;
    void draw() override;
};