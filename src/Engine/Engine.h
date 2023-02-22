//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_ENGINE_H
#define PHYSICSENGINE_ENGINE_H

#include "../World/Entity.h"
#include "../World/Chunk.h"
#include "./Math/Vector2.h"
#include <vector>
#include <array>

namespace Engine {
    class Engine {
    public:
        Engine() = default;
        Engine(float width, float height, std::vector<World::Entity>* entities);
        ~Engine() = default;

        void calculatePhysics(float deltaTime);
        void checkBounds(Body& body) const;
        void checkCollisions(Body& body, float deltaTime);
        void applyAcceleration(Body& body, float subDeltaTime);
        void updateGrid();

    private:
        float m_width{};
        float m_height{};

        static const int c_numCells{20};
        static const int c_substeps = 4;

        std::array<std::array<std::vector<int>, c_numCells>, c_numCells> m_grid{};
        std::vector<World::Entity>* m_entities;
    };
}

#endif //PHYSICSENGINE_ENGINE_H
