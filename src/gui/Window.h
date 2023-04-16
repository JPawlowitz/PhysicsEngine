//
// Created by Jan Pawlowitz on 06.03.23.
//

#ifndef PHYSICSENGINE_WINDOW_H
#define PHYSICSENGINE_WINDOW_H

#include "../engine/body/CircleBody.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Window {
public:
    Window(const int& width, const int& height);

    void updateWindow(std::vector<CircleBody>& bodies);
    bool isOpen() const { return m_window.isOpen(); }

private:
    sf::RenderWindow m_window;
    sf::RenderTexture m_renderTexture;
    sf::Sprite m_renderSprite{};

    sf::Texture m_spriteTexture;
    sf::Sprite m_sprite;
    sf::CircleShape m_circle{};

    sf::Font m_font;
};


#endif //PHYSICSENGINE_WINDOW_H
