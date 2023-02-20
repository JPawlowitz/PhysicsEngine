//
// Created by Jan Pawlowitz on 18.02.23.
//
#include "App.h"

App::App()
: m_window{sf::VideoMode{
    static_cast<unsigned int>(c_width),
    static_cast<unsigned int>(c_height), 32}, "Physics Engine"}
, m_world{c_width, c_height} {
    m_font.loadFromFile("./src/assets/Roboto-Regular.ttf");

    m_frameText = {"", m_font, m_textSize};
    const auto& textBounds = m_frameText.getGlobalBounds();
    m_frameText.setPosition(textBounds.width / 2, textBounds.height / 2);
    m_numObjectsText = {"", m_font, m_textSize};
    m_numObjectsText.setPosition(textBounds.width, textBounds.height + m_textSpacing);
}

void App::run() {
    auto clock = sf::Clock{};

    while(m_window.isOpen()){
        sf::Event event;
        while(m_window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                m_window.close();
            }
        }

        //Updating
        m_world.update(m_deltaTime);

        //Rendering
        m_window.clear(sf::Color::Black);

        for (auto entity : m_world.getEntities()) {
            m_window.draw(entity.getShape());
        }

        m_frameText.setString("Frame Time: " + std::to_string(m_deltaTime * 1000) + " ms");
        m_numObjectsText.setString("Objects: " + std::to_string(m_world.getNumEntities()));

        m_window.draw(m_world.getSpawnerShape());
        m_window.draw(m_frameText);
        m_window.draw(m_numObjectsText);

        m_window.display();

        m_deltaTime = clock.restart().asSeconds();
    }
}
