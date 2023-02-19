//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_PHYSICSBODY_H
#define PHYSICSENGINE_PHYSICSBODY_H

#include <SFML/Graphics.hpp>

class PhysicsBody {
public:
    PhysicsBody(float size, const sf::Vector2f& position);
    ~PhysicsBody() = default;

    const sf::CircleShape& getShape() { return m_shape; }
    sf::Vector2f getAcceleration() const { return m_acceleration; }
    float getVelocity() const { return m_velocity; }

    void setAcceleration(const sf::Vector2f& acceleration);
    void updatePosition(float deltaTime);

private:
    sf::CircleShape m_shape;
    sf::Vector2f m_acceleration{};
    float m_velocity{};
};


#endif //PHYSICSENGINE_PHYSICSBODY_H
