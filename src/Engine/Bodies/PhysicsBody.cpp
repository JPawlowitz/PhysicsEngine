//
// Created by Jan Pawlowitz on 19.02.23.
//

#include "PhysicsBody.h"
#include "../Math/Constants.h"

PhysicsBody::PhysicsBody(float size, const sf::Vector2f& position) {
    m_shape.setRadius(size / 2);
    m_shape.setPosition(position);
    m_acceleration = {-12.0f, 0.0f};
}

void PhysicsBody::setAcceleration(const sf::Vector2f &acceleration) {
    m_acceleration = acceleration;
}

void PhysicsBody::updatePosition(float deltaTime) {
    sf::Vector2f newPosition{m_shape.getPosition() + (m_acceleration * deltaTime * math::worldMultiplier)};
    m_shape.setPosition(newPosition);
}