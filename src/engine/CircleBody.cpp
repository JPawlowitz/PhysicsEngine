//
// Created by Jan Pawlowitz on 16.04.23.
//

#include "CircleBody.h"

CircleBody::CircleBody(const math::Vec2 &position, float mass, float radius)
: Body(position, mass), m_radius(radius) {}