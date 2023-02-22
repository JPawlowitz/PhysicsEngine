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

        m_pastelColors[0] = {251, 248, 204};
        m_pastelColors[1] = {253, 228, 207};
        m_pastelColors[2] = {255, 207, 210};
        m_pastelColors[3] = {241, 192, 232};
        m_pastelColors[4] = {163, 196, 243};
        m_pastelColors[5] = {144, 219, 244};
        m_pastelColors[6] = {142, 236, 245};
        m_pastelColors[7] = {152, 245, 225};
        m_pastelColors[8] = {185, 251, 192};
        m_pastelColors[9] = {207, 186, 240};
    }

    void BodySpawner::run(float deltaTime, std::vector<Entity> *entities) {
        m_timer += deltaTime;

        if (m_timer >= m_interval && m_numObjectsToSpawn > 0) {
            auto randomForceX = m_accelerationRange(m_randomGenerator);
            auto randomRadius = m_radiusRange(m_randomGenerator);

            Entity newEntity{m_spawnPosition, {randomForceX, 0.0f}, randomRadius};
            newEntity.applyColor(getRandomColor());
            entities->push_back(newEntity);

            m_timer = 0.0f;
            --m_numObjectsToSpawn;
        }
    }

    sf::Color BodySpawner::getRandomColor() {
        std::mt19937 randomGenerator{ std::random_device{}() };
        std::uniform_int_distribution range{0, static_cast<int>(m_pastelColors.size() - 1)};

        sf::Color defaultColor = {55, 55, 55};

        defaultColor.r = range(randomGenerator);
        defaultColor.g = range(randomGenerator);
        defaultColor.b = range(randomGenerator);

//        if (m_colorIterator <= 200) {
//            defaultColor.r += m_colorIterator;
//        } else if (m_colorIterator > 200 && m_colorIterator <= 400) {
//            defaultColor.r = 255;
//            defaultColor.g += m_colorIterator - 200;
//        } else if (m_colorIterator > 400 && m_colorIterator <= 600) {
//            defaultColor.r = 150;
//            defaultColor.g = 150;
//            defaultColor.b = m_colorIterator - 400;
//        }

        m_colorIterator += 3;
        return m_pastelColors[range(randomGenerator)];
    }
}