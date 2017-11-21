//
// Created by lasagnaphil on 11/21/17.
//

#ifndef MEM_ALLOC_BETTERPARTICLEMANAGER_H
#define MEM_ALLOC_BETTERPARTICLEMANAGER_H


#include "ParticleManager.h"

class BetterParticleManager : public ParticleManager {
public:
    BetterParticleManager(sf::RenderWindow& window) : ParticleManager(window) {

    }

    void createParticle() override {
        // TODO
        // Create a Particle and store its data
    }

    void removeDeadParticles() override {
        // TODO
        // Remove all currently dead particles
    }

    void update(const sf::Time& deltaTime) override {
        // TODO
        // Update all active particles
    }

    void draw() override {
        // TODO
        // Draw all active particles
    }

    unsigned long count() override {
        // TODO
        // Return the current number of active particles
        return 0;
    }
};


#endif //MEM_ALLOC_BETTERPARTICLEMANAGER_H
