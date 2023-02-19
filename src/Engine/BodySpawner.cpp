//
// Created by Jan Pawlowitz on 19.02.23.
//

#include "BodySpawner.h"

BodySpawner::BodySpawner(Engine &engineRef, const sf::Vector2f& spawnPosition) : m_engine(engineRef), m_spawnPosition(spawnPosition) {}
BodySpawner::BodySpawner(Engine &engineRef, const sf::Vector2f& spawnPosition, int numObjects) : m_engine(engineRef), m_spawnPosition(spawnPosition), m_numObjectsToSpawn(numObjects) {}
BodySpawner::BodySpawner(Engine &engineRef, const sf::Vector2f& spawnPosition, int numObjects, float interval) : m_engine(engineRef), m_spawnPosition(spawnPosition), m_numObjectsToSpawn(numObjects), m_interval(interval) {}

void BodySpawner::run(float deltaTime) {
    m_timer += deltaTime;

    if (m_timer >= m_interval && m_engine.getNumBodies() <= m_numObjectsToSpawn) {
        auto randomForceX = static_cast<float>(m_range(m_randomGenerator));

        PhysicsBody newBody{20.0f, m_spawnPosition};
        newBody.setAcceleration({-randomForceX, 0.0f});

        m_engine.addBody(newBody);

        m_timer = 0.0f;
    }
}