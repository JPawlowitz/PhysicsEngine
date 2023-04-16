//
// Created by Jan Pawlowitz on 16.04.23.
//

#include "Body.h"

Body::Body(const math::Vec2 &position, float mass)
: m_position(position), m_prev_position(position), m_mass(mass) {}

void Body::ApplyGravity(const math::Vec2 &gravity) {
    m_acceleration += gravity * m_mass;
}

void Body::ApplyForce(const math::Vec2& force) {
    m_acceleration += force;
}

void Body::UpdatePosition(float delta_time) {
    const math::Vec2 velocity = (m_position - m_prev_position) + m_acceleration * delta_time;
    m_prev_position = m_position;

    m_position += velocity * delta_time;
    m_acceleration.Set(0.0f, 0.0f);
}