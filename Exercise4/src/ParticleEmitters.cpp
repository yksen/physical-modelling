#include "ParticleEmitters.hpp"

namespace common
{
    auto short_time_generator = std::make_shared<TimeGenerator>(3, 6);
    auto long_time_generator = std::make_shared<TimeGenerator>(6, 12);
    auto random_color_generator = std::make_shared<RandomColorGenerator>();
}

StaticBoxEmitter::StaticBoxEmitter(float emit_rate, ofVec3f origin, ofVec3f range) : ParticleEmitter(emit_rate)
{
    addGenerator(common::short_time_generator);
    addGenerator(common::random_color_generator);
    addGenerator(std::make_shared<BoxPositionGenerator>(origin, range));
}

StaticSphereEmitter::StaticSphereEmitter(float emit_rate, ofVec3f origin, float radius) : ParticleEmitter(emit_rate)
{
    addGenerator(common::short_time_generator);
    addGenerator(common::random_color_generator);
    addGenerator(std::make_shared<SpherePositionGenerator>(origin, radius));
}

ExplosionEmitter::ExplosionEmitter(float emit_rate, ofVec3f origin, float power, ofColor min_color, ofColor max_color) : ParticleEmitter(emit_rate)
{
    addGenerator(common::short_time_generator);
    addGenerator(std::make_shared<RandomColorGenerator>(min_color, max_color));
    addGenerator(std::make_shared<SpherePositionGenerator>(origin, 1));
    addGenerator(std::make_shared<VelocityGenerator>(ofVec3f(-power), ofVec3f(power)));
}

SnowfallEmitter::SnowfallEmitter(float emit_rate, ofVec3f origin, float radius) : ParticleEmitter(emit_rate)
{
    addGenerator(common::long_time_generator);
    addGenerator(std::make_shared<RandomColorGenerator>(ofColor(120, 2230, 255), ofColor(255, 255, 255)));
    addGenerator(std::make_shared<CylinderPositionGenerator>(origin, radius, 1));
    addGenerator(std::make_shared<VelocityGenerator>(ofVec3f(0), ofVec3f(0)));
}