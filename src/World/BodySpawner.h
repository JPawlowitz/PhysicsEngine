//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_BODYSPAWNER_H
#define PHYSICSENGINE_BODYSPAWNER_H

#include "./Entity.h"
#include "ColorPalette.h"
#include "../Engine/Math/Vector2.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <array>

namespace World {
    class BodySpawner {
    public:
        BodySpawner() = default;
        BodySpawner(const sf::Vector2f& spawnPosition, int numObjects, float radius, float interval);
        ~BodySpawner() = default;

        void run(float deltaTime, std::vector<Entity> *entities);
        sf::Color getRandomColor();

        const sf::RectangleShape& getShape() { return m_shape; }

    private:
        sf::RectangleShape m_shape{};
        sf::Vector2f m_spawnPosition{};
        int m_numObjectsToSpawn{};
        int m_objectCounter{0};
        float m_interval{};
        float m_timer{};
        float m_previousDeltaTime{};

        std::mt19937 m_randomGenerator{ std::random_device{}() };
        std::uniform_real_distribution<float> m_accelerationRange{200.0f, 1500.0f};
        std::uniform_real_distribution<float> m_radiusRange{7.5f, 25.0f};
    };
}

#endif //PHYSICSENGINE_BODYSPAWNER_H