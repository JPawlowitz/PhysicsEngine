//
// Created by Jan Pawlowitz on 06.03.23.
//

#include "Window.h"

Window::Window(const int& width, const int& height)
: m_window {
    sf::VideoMode{
        static_cast<unsigned int>(width),
        static_cast<unsigned int>(height),
        32},
        "Physics Engine"
} {
    m_font.loadFromFile("./src/gui/assets/Roboto-Regular.ttf");
    m_spriteTexture.loadFromFile("./src/gui/assets/circle.png");
    m_sprite.setTexture(m_spriteTexture);
    m_sprite.setScale(0.05f, 0.05f);

    m_renderTexture.create(width, height);

    m_circle.setRadius(10.0f);
}

void Window::updateWindow(std::vector<CircleBody>& bodies) {
    sf::Event event;
    while(m_window.pollEvent(event)) {
        if(event.type == sf::Event::Closed){
            m_window.close();
        }
    }

    m_renderTexture.clear(sf::Color::Black);

    for (const auto& body : bodies) {
        const auto& pos = body.m_position;
        m_circle.setRadius(body.m_radius);
        m_circle.setPosition(pos.x - body.m_radius, pos.y - body.m_radius);
        m_renderTexture.draw(m_circle);
    }

    m_renderTexture.display();

    m_window.clear(sf::Color::Black);
    m_renderSprite.setTexture(m_renderTexture.getTexture());
    m_window.draw(m_renderSprite);
    m_window.display();
}