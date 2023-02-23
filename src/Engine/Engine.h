//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_ENGINE_H
#define PHYSICSENGINE_ENGINE_H

#include "../World/Entity.h"
#include "Grid.h"
#include "./Math/Vector2.h"
#include <vector>
#include <array>

namespace Engine {
    struct Chunk{
        std::vector<Body*> bodies;

        void reset() { bodies.clear(); }
    };

    class Engine {
    public:
        Engine() = default;
        Engine(float width, float height, std::vector<World::Entity>* entities);
        ~Engine() = default;

        void calculatePhysics(float deltaTime);
        void checkBounds(Body& body) const;
        void checkCollisions(Body& body, float deltaTime);
        void checkCollision(Body& firstBody, Body& secondBody, float deltaTime);
        void applyAcceleration(Body& body, float subDeltaTime);

    private:
        float m_width{};
        float m_height{};
        const int c_substeps = 4;

        std::vector<World::Entity>* m_entities{};
        Grid m_grid{};
    };
}

#endif //PHYSICSENGINE_ENGINE_H
