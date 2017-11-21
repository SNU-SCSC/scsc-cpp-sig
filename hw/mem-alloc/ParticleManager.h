//
// Created by lasagnaphil on 11/12/17.
//

#ifndef MEM_ALLOC_PARTICLEMANAGER_H
#define MEM_ALLOC_PARTICLEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "Constants.h"

class ParticleManager {
public:
    ParticleManager(sf::RenderWindow& window) : window(&window) {}

    virtual ~ParticleManager() {}

    virtual void createParticle() = 0;

    virtual void removeDeadParticles() = 0;

    virtual void update(const sf::Time& deltaTime) = 0;

    virtual void draw() = 0;

    virtual unsigned long count() = 0;

protected:

    sf::Vector2f randomPos() {
        return sf::Vector2f(
            static_cast<float>(std::rand() % Constants::screenWidth),
            static_cast<float>(std::rand() % Constants::screenHeight)
        );
    }

    sf::Vector2f randomVel() {
        float speed = static_cast<float>(std::rand() % Constants::maxParticleSpeed);
        float angle = (std::rand() % 360) / 360.f * 2 * 3.141592f;

        return sf::Vector2f(speed * std::cos(angle), speed * std::sin(angle));
    }

    float randomLifetime() {
        int lifetimeSpan = static_cast<int>(
            std::round(Constants::particleLifetimeMax - Constants::particleLifetimeMin)
        );
        return Constants::particleLifetimeMin + randomFloat() * lifetimeSpan;
    }

    sf::RenderWindow* window;
private:
    float randomFloat() {
        return static_cast<float>(std::rand()) / std::numeric_limits<int>::max();
    }
};


#endif //MEM_ALLOC_PARTICLEMANAGER_H
