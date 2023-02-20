//
// Created by Jan Pawlowitz on 18.02.23.
//
#include "App.h"
#include "./World/World.h"
#include <SFML/Graphics.hpp>

void App::run() {
    int width = 1920;
    int height = 1080;

    sf::RenderWindow window(sf::VideoMode(width,height,32),"Physics Engine");

    sf::Font font;
    font.loadFromFile("./src/assets/Roboto-Regular.ttf");
    sf::Text frameText("", font, 22);
    frameText.setPosition(frameText.getGlobalBounds().width / 2,frameText.getGlobalBounds().height / 2);

    sf::Text numObjectsText{"", font, 22};
    numObjectsText.setPosition(numObjectsText.getGlobalBounds().width, frameText.getPosition().y + 15.0f);

    World::World world{ width, height };

    auto clock = sf::Clock{};

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        //Updating
        world.update(m_deltaTime);

        //Rendering
        window.clear(sf::Color::Black);

        for (auto entity : world.getEntities()) {
            window.draw(entity.getShape());
        }

        frameText.setString("Frame Time: " + std::to_string(m_deltaTime * 1000) + " ms");
        numObjectsText.setString("Objects: " + std::to_string(world.getNumEntities()));

        //window.draw(bodySpawner.getShape());
        window.draw(frameText);
        window.draw(numObjectsText);

        window.display();

        m_deltaTime = clock.restart().asSeconds();
    }
}
