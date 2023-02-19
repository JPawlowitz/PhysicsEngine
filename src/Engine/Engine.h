//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_ENGINE_H
#define PHYSICSENGINE_ENGINE_H

#include "./Bodies/PhysicsBody.h"
#include <vector>

class Engine {
public:
    explicit Engine(float groundLevel);
    ~Engine() = default;

    void addBody(const PhysicsBody& newBody);

    std::vector<PhysicsBody>& getBodies();
    unsigned long getNumBodies() { return m_bodies.size(); }

    void runSimulation(float deltaTime);

private:
    std::vector<PhysicsBody> m_bodies;
    float m_groundLevel{};
};


#endif //PHYSICSENGINE_ENGINE_H
