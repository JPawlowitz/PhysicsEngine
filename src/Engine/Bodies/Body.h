//
// Created by Jan Pawlowitz on 20.02.23.
//

#ifndef PHYSICSENGINE_BODY_H
#define PHYSICSENGINE_BODY_H

#include "../Math/Vector2.h"
#include <SFML/Graphics.hpp>

class Body {
public:
    Body() = default;
    Body(const sf::Vector2f& position, const sf::Vector2f& initialForce, float radius);
    ~Body() = default;

    sf::Vector2f m_previousPosition{};
    sf::Vector2f m_currentPosition{};
    sf::Vector2f m_velocity{};
    sf::Vector2f m_acceleration{};

    float getRadius() const { return m_radius; }
    float getDiameter() const { return m_radius * 2; }
    float getMass() const { return m_mass; }

private:
    float m_radius{};
    float m_mass{150.0f};
};


#endif //PHYSICSENGINE_BODY_H
