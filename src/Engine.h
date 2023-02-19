//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_ENGINE_H
#define PHYSICSENGINE_ENGINE_H

#include "./Shapes/PhysicsBody.h"
#include <vector>

class Engine {
public:
    Engine() = default;
    ~Engine() = default;

private:
    std::vector<PhysicsBody> m_bodies;
};


#endif //PHYSICSENGINE_ENGINE_H
