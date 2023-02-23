//
// Created by Jan Pawlowitz on 20.02.23.
//

#include "Body.h"

Body::Body(const sf::Vector2f& position, const sf::Vector2f& initialForce, float radius, int index, float deltaTime)
: m_currentPosition{position},
m_previousPosition{sf::Vector2f {position.x + 0.5f, position.y}},
m_acceleration{initialForce * deltaTime},
m_radius{radius},
m_mass{radius * 9.0f},
c_index{index} {}
