//
// Created by lasagnaphil on 11/12/17.
//

#ifndef MEM_ALLOC_GAME_H
#define MEM_ALLOC_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "ParticleManager.h"
#include "VectorParticleManager.h"

#include "Constants.h"
#include "FrameClock.h"
#include "ClockHUD.h"
#include "BetterParticleManager.h"

class Game {
public:

    Game() : window(sf::VideoMode(Constants::screenWidth, Constants::screenHeight), "Memory Allocation"),
             manager(new VectorParticleManager(window)),
             clock(), font(),
             hud(clock, font)
    {
        std::srand(std::time(0));
        window.setVerticalSyncEnabled(true);
    }

    ~Game() {
        delete manager;
    }

    void reset() {
        clock.clear();
        updateClock.clear();
    }

    void gameLoop() {
        clock.beginFrame();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                switch(event.key.code) {
                    case sf::Keyboard::Up:
                        manager->createParticle(); break;
                    case sf::Keyboard::Num1:
                        delete manager;
                        manager = new VectorParticleManager(window);
                        reset(); return;
                    case sf::Keyboard::Num2:
                        delete manager;
                        manager = new BetterParticleManager(window);
                        reset(); return;
                }
            }
        }
        sf::Time frameTime = clock.getLastFrameTime();
        updateClock.beginFrame();
        this->update(frameTime);
        updateClock.endFrame();

        frameInfoText.setString(
            std::to_string(manager->count()) + " particles\n" +
            std::to_string(updateClock.getAverageFrameTime().asMicroseconds()) + " microsec"
        );

        window.clear(sf::Color(0, 0, 0));
        this->draw();
        window.draw(hud);
        window.draw(frameInfoText);

        window.display();

        clock.endFrame();
    }

    void start() {

        if (!font.loadFromFile("Inconsolata-Regular.ttf")) {
            std::cerr << "Cannot find font Inconsolata-Regular.ttf!" << std::endl;
            return;
        }
        frameInfoText.setFont(font);
        frameInfoText.setPosition(Constants::screenWidth - 300, 0);

        clock.setSampleDepth(60);

        const sf::Time updateMs = sf::seconds(1.f / 60.f);
        while (window.isOpen()) {
            gameLoop();
        }
    }

    void update(const sf::Time& deltaTime) {
        manager->update(deltaTime);
        emitTimer += deltaTime;
        while (emitTimer >= Constants::emitTimespan) {
            for (int i = 0; i < Constants::emitAmount; ++i) {
                manager->createParticle();
            }
            emitTimer -= Constants::emitTimespan;
        }
        manager->removeDeadParticles();
    }

    void draw() {
        manager->draw();
    }

private:
    sf::RenderWindow window;
    ParticleManager* manager;
    sf::Text frameInfoText;
    sf::Font font;
    sf::Time emitTimer;

    sfx::FrameClock clock;
    sfx::FrameClock updateClock;
    ClockHUD hud;
};

#endif //MEM_ALLOC_GAME_H
