#pragma once

#include "Object.h"

class Disk : public Object
{
public:
    using Object::Object;

    void update() override;

    void applyDrag();
};