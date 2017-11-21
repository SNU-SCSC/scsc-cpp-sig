//
// Created by lasagnaphil on 11/12/17.
//

#ifndef MEM_ALLOC_VECTORPARTICLEMANAGER_H
#define MEM_ALLOC_VECTORPARTICLEMANAGER_H

#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include "ParticleManager.h"
#include "Particle.h"

class VectorParticleManager : public ParticleManager {
public:
    VectorParticleManager(sf::RenderWindow& window) : ParticleManager(window) {}

    void createParticle() override {
        particles.emplace_back(randomPos(), randomVel(), randomLifetime());
    }

    void removeDeadParticles() override {
        particles.erase(std::remove_if(particles.begin(),
                                       particles.end(),
                                       [](Particle& p) { return !p.isActive(); }),
                        particles.end());
    }

    void update(const sf::Time& deltaTime) override {
        for (auto& particle : particles) {
            particle.update(deltaTime);
        }
    }

    void draw() override {
        for (auto& particle : particles) {
            particle.draw(*window);
        }
    }

    unsigned long count() override {
        return particles.size();
    }

private:
    std::vector<Particle> particles;
};


#endif //MEM_ALLOC_VECTORPARTICLEMANAGER_H
