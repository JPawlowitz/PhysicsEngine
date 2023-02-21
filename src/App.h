//
// Created by Jan Pawlowitz on 18.02.23.
//

#ifndef PHYSICSENGINE_APP_H
#define PHYSICSENGINE_APP_H

#include "./World/World.h"
#include <SFML/Graphics.hpp>
#include <array>

class App {
public:
    App();
    ~App() = default;

    void run();

private:
    const int c_width{1920};
    const int c_height{1080};

    sf::RenderWindow m_window{};
    sf::Font m_font{};
    unsigned int m_textSize{26};
    float m_textSpacing{30.0f};

    std::array<sf::Text, 4> m_texts{};

    World::World m_world{};
    float m_deltaTime{};
};

#endif //PHYSICSENGINE_APP_H
