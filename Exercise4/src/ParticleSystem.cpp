#include "ParticleSystem.hpp"

ParticleEmitter::ParticleEmitter(size_t count, ParticleData *particles)
    : start_id(particles->count), end_id(particles->count + count)
{
}

void ParticleEmitter::emit()
{
    for (auto &generator : generators)
        generator->generate(start_id, end_id);
}

void ParticleEmitter::addGenerator(shared_ptr<ParticleGenerator> generator)
{
    generators.push_back(generator);
}

void ParticleSystem::draw()
{
    for (size_t i = 0; i < particles.count; ++i)
    {
        ofSetColor(particles.color->at(i));
        ofDrawSphere(particles.position->at(i), 10);
    }
}

void ParticleSystem::update()
{
    for (auto &emitter : emitters)
        emitter->emit();

    for (auto &updater : updaters)
        updater->update();
}

void ParticleSystem::addEmitter(std::shared_ptr<ParticleEmitter> emitter)
{
    emitters.push_back(emitter);
}

void ParticleSystem::addUpdater(std::shared_ptr<ParticleUpdater> updater)
{
    updaters.push_back(updater);
}