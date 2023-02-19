//
// Created by Jan Pawlowitz on 18.02.23.
//
#include "App.h"
#include <SFML/Graphics.hpp>

void App::run() {
    sf::RenderWindow window(sf::VideoMode(640,480,32),"Physics Engine");

    sf::Font font;
    font.loadFromFile("./src/assets/Roboto-Regular.ttf");
    sf::Text text("FPS",font,11);
    text.setCharacterSize(22);
    text.setPosition(text.getGlobalBounds().width/2,
                     text.getGlobalBounds().height/2);

    sf::Vector2f center {static_cast<float>(window.getSize().x / 2), static_cast<float>(window.getSize().y / 2)};

    sf::CircleShape circle;
    circle.setRadius(10.f);
    circle.setPosition(center);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }
            window.clear(sf::Color::Black);
            window.draw(circle);
            window.draw(text);
            window.display();
        }
    }
}
