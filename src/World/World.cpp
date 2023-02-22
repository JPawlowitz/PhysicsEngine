//
// Created by Jan Pawlowitz on 19.02.23.
//

#include "World.h"
#include <iostream>

namespace World {
    World::World(float width, float height)
    : m_engine{width, height, &m_entities}, m_spawner{{width - 40.0f, 20.0f}, 500, 20.0f, 0.1f}
    , m_width{width}, m_height{height} {
        m_entities.reserve(200);
    }

    void World::update(float deltaTime) {
        m_spawner.run(deltaTime, &m_entities);

        m_engine.calculatePhysics(deltaTime);

        //assignChunks();
    }
}