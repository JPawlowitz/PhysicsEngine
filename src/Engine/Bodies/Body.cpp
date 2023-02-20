//
// Created by Jan Pawlowitz on 20.02.23.
//

#include "Body.h"

Body::Body(sf::Vector2f position, sf::Vector2f initialForce, float radius)
: m_position{position}, m_force{initialForce}, m_radius{radius} {}

sf::Vector2f Body::getCenter() {
    return {m_position.x + m_radius, m_position.y + m_radius};
}