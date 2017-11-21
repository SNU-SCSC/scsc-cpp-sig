//
// Created by lasagnaphil on 11/12/17.
//

#ifndef MEM_ALLOC_PARTICLE_H
#define MEM_ALLOC_PARTICLE_H

#include <SFML/Graphics/CircleShape.hpp>
#include "Game.h"
#include "Constants.h"

class Particle {
public:
    Particle() : Particle(sf::Vector2f(), sf::Vector2f(), -1.f) {}
    Particle(const sf::Vector2f& pos, const sf::Vector2f& vel, float lifetime)
            : ball(Constants::particleSize),
              velocity(vel),
              lifetime(lifetime),
              origLifetime(lifetime)
    {
        ball.setFillColor(sf::Color::Yellow);
        ball.setOrigin(ball.getRadius(), ball.getRadius());
        ball.setPosition(pos);
    }

#if 1
    Particle* getNext() const { return next; }
    void setNext(Particle* next) { this->next = next; }
#endif

    void reset(const sf::Vector2f& pos, const sf::Vector2f& vel, float lifetime) {
        this->velocity = vel;
        this->lifetime = lifetime;
        this->origLifetime = lifetime;
        ball.setPosition(pos);
    }

    bool update(const sf::Time& deltaTime) {
        if (!isActive()) return false;
        float dt = deltaTime.asSeconds();

        auto pos = ball.getPosition() + velocity * dt;
        if (pos.x < 0) {
            pos.x = -pos.x;
            velocity.x = -velocity.x;
        }
        if (pos.x > Constants::screenWidth) {
            pos.x = 2 * Constants::screenWidth - pos.x;
            velocity.x = -velocity.x;
        }
        if (pos.y < 0) {
            pos.y = -pos.y;
            velocity.y = -velocity.y;
        }
        if (pos.y > Constants::screenHeight) {
            pos.y = 2 * Constants::screenHeight - pos.y;
            velocity.y = -velocity.y;
        }

        ball.setPosition(pos);
        if (lifetime > 0.f) lifetime -= dt;
        return !isActive();
    }

    void draw(sf::RenderWindow& window) {
        auto green = static_cast<uint8_t>(
            std::clamp(255 * (lifetime / origLifetime), 0.f, 255.f)
        );
        ball.setFillColor(sf::Color(255, green, 0));
        window.draw(ball);
    }

    bool isActive() const {
        return lifetime > 0.f;
    }

private:
    sf::CircleShape ball;
    sf::Vector2f velocity;
    float origLifetime;
    float lifetime;

#if 1
    Particle* next;
#endif
};


#endif //MEM_ALLOC_PARTICLE_H
