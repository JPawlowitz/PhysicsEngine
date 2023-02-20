//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_ENGINE_H
#define PHYSICSENGINE_ENGINE_H

#include "../World/Entity.h"
#include <vector>

class Engine {
public:
    Engine() = default;
    Engine(int width, int height);
    ~Engine() = default;

    void calculatePhysics(float deltaTime, std::vector<World::Entity> *entities);
    sf::Vector2f getDistanceCircles(const sf::Vector2f& firsVector, const sf::Vector2f& secondVector);


private:
    int m_width{};
    int m_height{};
};


#endif //PHYSICSENGINE_ENGINE_H
