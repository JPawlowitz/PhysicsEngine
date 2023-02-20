//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_WORLD_H
#define PHYSICSENGINE_WORLD_H

#include "Entity.h"
#include "../Engine/Engine.h"
#include "BodySpawner.h"
#include <vector>

namespace World {
    class World {
    public:
        World(int width, int height);
        ~World() = default;

        const std::vector<Entity>& getEntities() { return m_entities; }
        const sf::Shape& getSpawnerShape() { return m_spawner.getShape(); }

        void update(float deltaTime);
        unsigned long getNumEntities() { return m_entities.size(); }

    private:
        std::vector<Entity> m_entities;

        Engine m_engine{};
        BodySpawner m_spawner{};
    };
}

#endif //PHYSICSENGINE_WORLD_H
