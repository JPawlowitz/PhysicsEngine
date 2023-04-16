//
// Created by Jan Pawlowitz on 18.02.23.
//
#include "App.h"

App::App(int width, int height)
: m_window(sf::VideoMode(width, height), "PhysicsEngine")
, c_width{width}, c_height{height} {}

void App::Start() {
    Run();
}

void App::Run() {
    auto dtClock = sf::Clock{};

    while(m_window.isOpen()){
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        Draw();

        m_dt = dtClock.restart().asSeconds();
    }
}

void App::Draw() {
    // clear the window with black color
    m_window.clear(sf::Color::Black);


    m_window.display();
}