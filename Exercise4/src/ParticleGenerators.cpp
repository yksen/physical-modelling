#include "ParticleGenerators.hpp"

void BoxPositionGenerator::generate(ParticleData *particles, size_t start_id, size_t end_id)
{
    for (size_t i = start_id; i < end_id; ++i)
    {
        particles->position.at(i) = ofVec3f(
            ofRandom(origin.x - range.x, origin.x + range.x),
            ofRandom(origin.y - range.y, origin.y + range.y),
            ofRandom(origin.z - range.z, origin.z + range.z));
    }
}