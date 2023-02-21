//
// Created by Jan Pawlowitz on 19.02.23.
//

#include "BodySpawner.h"

namespace World {

    World::BodySpawner::BodySpawner(const sf::Vector2f &spawnPosition, int numObjects, float radius, float interval)
    : m_spawnPosition{spawnPosition}, m_numObjectsToSpawn{numObjects}, m_diameter{radius}, m_interval{interval}
    {
        m_shape.setSize({radius * 4, radius * 2});
        m_shape.setPosition({m_spawnPosition.x, m_spawnPosition.y - radius});
        m_shape.setFillColor(sf::Color::Blue);
    }

    void BodySpawner::run(float deltaTime, std::vector<Entity> *entities) {
        m_timer += deltaTime;

        if (m_timer >= m_interval && m_numObjectsToSpawn > 0) {
            auto randomForceX = m_range(m_randomGenerator);

            Entity newEntity{m_spawnPosition, {-randomForceX, 0.0f}, m_diameter};
            entities->push_back(newEntity);

            m_timer = 0.0f;
            --m_numObjectsToSpawn;
        }
    }
}