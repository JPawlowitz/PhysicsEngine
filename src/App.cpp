//
// Created by Jan Pawlowitz on 18.02.23.
//
#include "App.h"

App::App()
: m_window{sf::VideoMode{
    static_cast<unsigned int>(c_width),
    static_cast<unsigned int>(c_height), 32}, "Physics Engine"}
, m_world{static_cast<float>(c_width), static_cast<float>(c_height)} {
    m_font.loadFromFile("./src/assets/Roboto-Regular.ttf");

    for (int i = 0; i < m_texts.size(); ++i) {
        sf::Text newText{"", m_font, m_textSize};
        newText.setPosition({newText.getGlobalBounds().width, newText.getGlobalBounds().height + (i * m_textSpacing)});
        m_texts[i] = newText;
    }
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

//            m_texts[2].setString("VelocityX: " + std::to_string(entity.m_body.m_velocity.x));
//            m_texts[3].setString("VelocityY: " + std::to_string(entity.m_body.m_velocity.y));

//            sf::RectangleShape velocityX{{entity.m_body.m_velocity.x * 0.2f, 5.0f}};
//            sf::RectangleShape velocityY{{5.0f, entity.m_body.m_velocity.y * 0.2f}};
//            sf::RectangleShape accX{{entity.m_body.m_acceleration.x * 0.2f, 3.0f}};
//            sf::RectangleShape accY{{3.0f, entity.m_body.m_acceleration.y * 0.2f}};
//
//            velocityX.setFillColor(sf::Color::Red);
//            velocityY.setFillColor(sf::Color::Red);
//            accX.setFillColor(sf::Color::Blue);
//            accY.setFillColor(sf::Color::Blue);
//
//            velocityX.setPosition(entity.m_body.m_position);
//            velocityY.setPosition(entity.m_body.m_position);
//            accX.setPosition(entity.m_body.m_position);
//            accY.setPosition(entity.m_body.m_position);
//
//            m_window.draw(velocityX);
//            m_window.draw(velocityY);
//            m_window.draw(accX);
//            m_window.draw(accY);
        }

        m_texts[0].setString("FPS: " + std::to_string(static_cast<int>(1 / m_deltaTime)));
        m_texts[1].setString("Frame Time: " + std::to_string(m_deltaTime * 1000) + " ms");
        m_texts[2].setString("Objects: " + std::to_string(m_world.getNumEntities()));

        for (auto& text : m_texts) {
            m_window.draw(text);
        }

        m_window.draw(m_world.getSpawnerShape());

        m_window.display();

        m_deltaTime = clock.restart().asSeconds();
    }
}
