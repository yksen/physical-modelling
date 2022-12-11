#include "ParticleEmitters.hpp"

namespace common
{
    auto time_generator = std::make_shared<TimeGenerator>();
    auto random_color_generator = std::make_shared<RandomColorGenerator>();
}

StaticBoxEmitter::StaticBoxEmitter(float emit_rate, ofVec3f origin, ofVec3f range) : ParticleEmitter(emit_rate)
{
    addGenerator(common::time_generator);
    addGenerator(common::random_color_generator);
    addGenerator(std::make_shared<BoxPositionGenerator>(origin, range));
}

StaticSphereEmitter::StaticSphereEmitter(float emit_rate, ofVec3f origin, float radius) : ParticleEmitter(emit_rate)
{
    addGenerator(common::time_generator);
    addGenerator(common::random_color_generator);
    addGenerator(std::make_shared<SpherePositionGenerator>(origin, radius));
}