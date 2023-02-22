//
// Created by Jan Pawlowitz on 20.02.23.
//

#include "Body.h"

Body::Body(const sf::Vector2f& position, const sf::Vector2f& initialForce, float radius)
: m_currentPosition{position}
, m_previousPosition{sf::Vector2f {position.x + 0.5f, position.y}}
, m_acceleration{initialForce}
, m_radius{radius} {}
