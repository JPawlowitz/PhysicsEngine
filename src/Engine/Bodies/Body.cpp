//
// Created by Jan Pawlowitz on 20.02.23.
//

#include "Body.h"

Body::Body(sf::Vector2f position, sf::Vector2f initialForce, float diameter)
: m_position{position}, m_force{initialForce}, m_diameter{diameter} {}