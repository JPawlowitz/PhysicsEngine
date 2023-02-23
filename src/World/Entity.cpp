//
// Created by Jan Pawlowitz on 20.02.23.
//

#include "Entity.h"

namespace World {
    Entity::Entity(const sf::Vector2f& position, const sf::Vector2f& initialForce, float radius, int index, float deltaTime)
    : m_body{position, initialForce, radius, index, deltaTime} {
        m_shape.setRadius(m_body.getRadius());
        m_shape.setPosition({position.x, position.y});
    }

    void Entity::updatePosition() {
        m_shape.setPosition({m_body.m_currentPosition.x - m_body.getRadius(), m_body.m_currentPosition.y - m_body.getRadius()});
    }
}

