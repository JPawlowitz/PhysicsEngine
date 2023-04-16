//
// Created by Jan Pawlowitz on 16.04.23.
//

#include "../libs/Math.h"

#ifndef PHYSICSENGINE_BODY_H
#define PHYSICSENGINE_BODY_H

class Body {
public:
    Body(const math::Vec2& position, float mass);

    void ApplyGravity(const math::Vec2& gravity);
    void ApplyForce(const math::Vec2& force);
    void UpdatePosition(float delta_time);

protected:
    math::Vec2 m_position;
    math::Vec2 m_prev_position;
    math::Vec2 m_acceleration{};
    const float m_mass;
};


#endif //PHYSICSENGINE_BODY_H
