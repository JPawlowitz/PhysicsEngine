//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_PHYSICSBODY_H
#define PHYSICSENGINE_PHYSICSBODY_H

#include "../Math/Vector2.h"

class PhysicsBody {
public:
    explicit PhysicsBody(const Vector2& position);
    ~PhysicsBody() = default;

private:
    Vector2 m_position;
};


#endif //PHYSICSENGINE_PHYSICSBODY_H
