//
// Created by Jan Pawlowitz on 20.02.23.
//

#ifndef PHYSICSENGINE_ENTITY_H
#define PHYSICSENGINE_ENTITY_H

#include "../Engine/Bodies/Body.h"
#include <SFML/Graphics.hpp>

namespace World {
    class Entity {
    public:
        Entity(const sf::Vector2f& position, const sf::Vector2f& initialForce, float diameter);
        ~Entity() = default;

        Body m_body{};

        const sf::CircleShape& getShape() { return m_shape; }

        void updatePosition() { m_shape.setPosition(m_body.m_position); }

    private:
        sf::CircleShape m_shape{};
    };
}

#endif //PHYSICSENGINE_ENTITY_H