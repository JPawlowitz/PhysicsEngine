//
// Created by Jan Pawlowitz on 20.02.23.
//

#include "Entity.h"

namespace World {
    Entity::Entity(const sf::Vector2f &position, const sf::Vector2f &initialForce, float diameter)
    : m_body{position, initialForce, 2 * diameter} {
        m_shape.setRadius(m_body.getDiameter());
        m_shape.setPosition(m_body.m_position);
    }
}

