//
// Created by Jan Pawlowitz on 16.04.23.
//

#ifndef PHYSICSENGINE_CIRCLEBODY_H
#define PHYSICSENGINE_CIRCLEBODY_H

#include "Body.h"

class CircleBody: public Body {
public:
    CircleBody(const math::Vec2& position, float mass, float radius);

private:
    const float m_radius;
};


#endif //PHYSICSENGINE_CIRCLEBODY_H
