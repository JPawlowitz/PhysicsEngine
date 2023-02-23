//
// Created by Jan Pawlowitz on 20.02.23.
//

#ifndef PHYSICSENGINE_ENTITY_H
#define PHYSICSENGINE_ENTITY_H

#include "../Engine/Bodies/Body.h"
#include "../Engine/Math/Vector2.h"
#include <SFML/Graphics.hpp>

namespace World {
    class Entity {
    public:
        Entity(const sf::Vector2f& position, const sf::Vector2f& initialForce, float diameter, int index, float deltaTime);
        ~Entity() = default;

        Body m_body{};

        const sf::CircleShape& getShape() { return m_shape; }

        void applyColor(const sf::Color& color) { m_shape.setFillColor(color); }
        void updatePosition();

    private:
        sf::CircleShape m_shape{};
    };
}

#endif //PHYSICSENGINE_ENTITY_H