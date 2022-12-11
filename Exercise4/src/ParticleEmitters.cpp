#include "ParticleEmitters.hpp"

namespace common
{
    auto time_generator = std::make_shared<TimeGenerator>(2, 4);
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

ExplosionEmitter::ExplosionEmitter(float emit_rate, ofVec3f origin, float power) : ParticleEmitter(emit_rate)
{
    addGenerator(common::time_generator);
    addGenerator(std::make_shared<RandomColorGenerator>(ofColor(255, 0, 0), ofColor(255, 255, 0)));
    addGenerator(std::make_shared<SpherePositionGenerator>(origin, 1));
    addGenerator(std::make_shared<VelocityGenerator>(ofVec3f(-power), ofVec3f(power)));
}