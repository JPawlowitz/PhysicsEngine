//
// Created by Jan Pawlowitz on 19.02.23.
//

#include "BodySpawner.h"

namespace World {
    BodySpawner::BodySpawner(const sf::Vector2f &spawnPosition, int numObjects, float radius, float interval)
    : m_spawnPosition{spawnPosition}, m_numObjectsToSpawn{numObjects}, m_interval{interval}
    {
        m_shape.setSize({radius * 4, radius * 2});
        m_shape.setPosition({m_spawnPosition.x, m_spawnPosition.y - radius});
        m_shape.setFillColor(sf::Color::Red);
    }

    void BodySpawner::run(float deltaTime, std::vector<Entity> *entities) {
        m_timer += deltaTime;

        if (m_timer >= m_interval && m_numObjectsToSpawn > 0) {
            auto randomForceX = m_accelerationRange(m_randomGenerator);
            auto randomRadius = m_radiusRange(m_randomGenerator);

            Entity newEntity{m_spawnPosition, {randomForceX, 0.0f}, randomRadius, m_objectCounter, deltaTime};
            newEntity.applyColor(getRandomColor());
            entities->push_back(newEntity);

            m_timer = 0.0f;
            --m_numObjectsToSpawn;
            m_objectCounter++;
        }

        m_previousDeltaTime = deltaTime;
    }

    sf::Color BodySpawner::getRandomColor() {
        std::mt19937 randomGenerator{ std::random_device{}() };
        std::uniform_int_distribution range{0, static_cast<int>(Colors::pastelPalette.size() - 1)};

        return Colors::pastelPalette[range(randomGenerator)];
    }
}