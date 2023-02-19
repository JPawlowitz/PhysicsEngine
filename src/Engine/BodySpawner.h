//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_BODYSPAWNER_H
#define PHYSICSENGINE_BODYSPAWNER_H

#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <random>

class BodySpawner {
public:
    BodySpawner(Engine& engineRef, const sf::Vector2f& spawnPosition);
    BodySpawner(Engine& engineRef, const sf::Vector2f& spawnPosition, int numObjects);
    BodySpawner(Engine& engineRef, const sf::Vector2f& spawnPosition, int numObjects, float interval);
    ~BodySpawner() = default;

    void run(float deltaTime);

private:
    Engine& m_engine;

    sf::Vector2f m_spawnPosition{};
    int m_numObjectsToSpawn{10};
    float m_interval{1.0f};
    float m_timer{};

    std::mt19937 m_randomGenerator{ std::random_device{}() };
    std::uniform_int_distribution<int> m_range{4, 14};
};


#endif //PHYSICSENGINE_BODYSPAWNER_H
