//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_BODYSPAWNER_H
#define PHYSICSENGINE_BODYSPAWNER_H

#include "../Engine/Engine.h"
#include <SFML/Graphics.hpp>
#include <random>

namespace World {
    class BodySpawner {
    public:
        BodySpawner() = default;
        BodySpawner(const sf::Vector2f& spawnPosition, int numObjects, float radius, float interval);
        ~BodySpawner() = default;

        void run(float deltaTime, std::vector<Entity> *entities);

        const sf::RectangleShape& getShape() { return m_shape; }

    private:
        sf::RectangleShape m_shape{};
        sf::Vector2f m_spawnPosition{};
        int m_numObjectsToSpawn{};
        float m_diameter{};
        float m_interval{};
        float m_timer{};

        std::mt19937 m_randomGenerator{ std::random_device{}() };
        std::uniform_real_distribution<float> m_range{1000.0f, 2000.0f};
    };
}

#endif //PHYSICSENGINE_BODYSPAWNER_H