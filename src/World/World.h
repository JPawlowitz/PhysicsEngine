//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_WORLD_H
#define PHYSICSENGINE_WORLD_H

#include "Entity.h"
#include "Chunk.h"
#include "../Engine/Engine.h"
#include "BodySpawner.h"
#include <vector>
#include <array>

namespace World {

    class World {
    public:
        World() = default;
        World(float width, float height);
        ~World() = default;

        const std::vector<Entity>& getEntities() { return m_entities; }
        const sf::Shape& getSpawnerShape() { return m_spawner.getShape(); }

        void update(float deltaTime);
        void assignChunks();
        unsigned long getNumEntities() { return m_entities.size(); }

        std::array<std::array<Chunk, 5>, 5> m_chunks;

    private:
        std::vector<Entity> m_entities;

        Engine::Engine m_engine{};
        BodySpawner m_spawner{};

        float m_width{};
        float m_height{};

        const int c_numChunks{5};
    };
}

#endif //PHYSICSENGINE_WORLD_H
