#include "ParticleSystem.hpp"

void ParticleData::generate(size_t count)
{
    this->count = count;
    alive.resize(count);
    color.resize(count);
    position.resize(count);
    velocity.resize(count);
    acceleration.resize(count);
}

void ParticleEmitter::emit(ParticleData *particles)
{
    for (auto &generator : generators)
        generator->generate(particles, start_id, end_id);
}

void ParticleEmitter::addGenerator(std::shared_ptr<ParticleGenerator> generator)
{
    generators.push_back(generator);
}

void ParticleSystem::draw()
{
    for (size_t i = 0; i < particles.count; ++i)
    {
        ofSetColor(particles.color.at(i));
        ofDrawSphere(particles.position.at(i), 10);
    }
}

void ParticleSystem::update()
{
    for (auto &emitter : emitters)
        emitter->emit(&particles);

    for (auto &updater : updaters)
        updater->update();
}

void ParticleSystem::addEmitter(std::shared_ptr<ParticleEmitter> emitter)
{
    particles.generate(particles.count + emitter->end_id - emitter->start_id);
    emitters.push_back(emitter);
}

void ParticleSystem::addUpdater(std::shared_ptr<ParticleUpdater> updater)
{
    updaters.push_back(updater);
}