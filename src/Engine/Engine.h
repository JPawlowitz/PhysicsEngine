//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_ENGINE_H
#define PHYSICSENGINE_ENGINE_H

#include "../World/Entity.h"
#include <vector>

class Engine {
public:
    Engine() = default;
    Engine(float width, float height);
    ~Engine() = default;

    void calculatePhysics(float deltaTime, std::vector<World::Entity> *entities);
    void checkBounds(Body& body) const;
    void checkCollision();

private:
    float m_width{};
    float m_height{};
};


#endif //PHYSICSENGINE_ENGINE_H
