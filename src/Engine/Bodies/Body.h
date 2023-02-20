//
// Created by Jan Pawlowitz on 20.02.23.
//

#ifndef PHYSICSENGINE_BODY_H
#define PHYSICSENGINE_BODY_H

#include <SFML/Graphics.hpp>

class Body {
public:
    Body() = default;
    Body(sf::Vector2f position, sf::Vector2f initialForce, float diameter);
    ~Body() = default;

    sf::Vector2f m_position;
    sf::Vector2f m_force;

    float getDiameter() const { return m_diameter; }

private:
    float m_diameter{};
};


#endif //PHYSICSENGINE_BODY_H
