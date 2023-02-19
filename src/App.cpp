//
// Created by Jan Pawlowitz on 18.02.23.
//
#include "App.h"
#include "Engine/Engine.h"
#include "./Engine/BodySpawner.h"
#include <SFML/Graphics.hpp>

void App::run() {
    sf::RenderWindow window(sf::VideoMode(640,480,32),"Physics Engine");

    sf::Font font;
    font.loadFromFile("./src/assets/Roboto-Regular.ttf");
    sf::Text frameText("", font, 12);
    frameText.setPosition(frameText.getGlobalBounds().width / 2,frameText.getGlobalBounds().height / 2);

    sf::Text numObjectsText{"", font, 12};
    numObjectsText.setPosition(numObjectsText.getGlobalBounds().width, frameText.getPosition().y + 15.0f);

    Engine engine{static_cast<float>(window.getSize().y)};
    engine.addBody({20.0f, sf::Vector2<float>{window.getSize().x - 10.0f, 0.0f}});

    BodySpawner bodySpawner{engine, sf::Vector2<float>{window.getSize().x - 10.0f, 0.0f}, 50, 0.25f};

    auto clock = sf::Clock{};

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        //Updating
        bodySpawner.run(m_deltaTime);
        engine.runSimulation(m_deltaTime);

        //Rendering
        window.clear(sf::Color::Black);

        for (auto& body : engine.getBodies()) {
            window.draw(body.getShape());
        }

        frameText.setString("Frame Time: " + std::to_string(m_deltaTime * 1000) + " ms");
        numObjectsText.setString("Objects: " + std::to_string(engine.getNumBodies()));

        window.draw(frameText);
        window.draw(numObjectsText);

        window.display();

        m_deltaTime = clock.restart().asSeconds();
    }
}
