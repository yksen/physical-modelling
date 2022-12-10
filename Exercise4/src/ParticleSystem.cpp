#include "ParticleSystem.hpp"

void ParticleData::generate(size_t count)
{
    this->count = count;
    alive.resize(count, false);
    time.resize(count);
    color.resize(count);
    position.resize(count);
    velocity.resize(count);
    acceleration.resize(count);
}

void ParticleData::kill(size_t index)
{
    alive.at(index) = false;
    swap(index, alive_count - 1);
    --alive_count;
}

void ParticleData::wake(size_t index)
{
    alive.at(index) = true;
    ++alive_count;
}

void ParticleData::swap(size_t first, size_t second)
{
    time.at(first) = time.at(second);
    color.at(first) = color.at(second);
    position.at(first) = position.at(second);
    velocity.at(first) = velocity.at(second);
    acceleration.at(first) = acceleration.at(second);
}

void ParticleEmitter::emit(ParticleData *particles, float dt)
{
    size_t max_new_particles = size_t(dt * emit_rate);
    size_t start_id = particles->alive_count;
    size_t end_id = std::min(start_id + max_new_particles, particles->count - 1);

    for (auto &generator : generators)
        generator->generate(particles, dt, start_id, end_id);

    for (size_t i = start_id; i < end_id; ++i)
        particles->wake(i);
}

void ParticleEmitter::addGenerator(std::shared_ptr<ParticleGenerator> generator)
{
    generators.push_back(generator);
}

ParticleSystem::ParticleSystem(size_t max_particle_count)
{
    particles.generate(max_particle_count);
}

void ParticleSystem::draw()
{
    for (size_t i = 0; i < particles.alive_count; ++i)
    {
        ofSetColor(particles.color.at(i));
        ofDrawSphere(particles.position.at(i), 10);
    }
}

void ParticleSystem::update(float dt)
{
    for (auto &emitter : emitters)
        emitter->emit(&particles, dt);

    for (auto &updater : updaters)
        updater->update(&particles, dt);
}

void ParticleSystem::addEmitter(std::shared_ptr<ParticleEmitter> emitter)
{
    emitters.push_back(emitter);
}

void ParticleSystem::addUpdater(std::shared_ptr<ParticleUpdater> updater)
{
    updaters.push_back(updater);
}