//
// Created by Jan Pawlowitz on 19.02.23.
//

#include "Engine.h"
#include "./Math/Constants.h"
#include <cmath>

Engine::Engine(int width, int height) : m_width{width}, m_height{height} {}

void Engine::calculatePhysics(float deltaTime, std::vector<World::Entity> *entities) {
    for (auto& entity : *entities) {
        auto& body = entity.m_body;

        if (body.m_position.y < m_height - body.getDiameter()) {
            if (body.m_position.x < 0.0f) {
                body.m_force = { -body.m_force.x, body.m_force.y };
            }

            if (body.m_position.x + body.getDiameter() > m_width) {
                body.m_force = { -body.m_force.x, body.m_force.y };
            }

            for (auto& neighbour : *entities) {
                auto& neighbourBody = neighbour.m_body;

                if (body.m_position != neighbourBody.m_position) {
                    auto distance = neighbourBody.getCenter() - body.getCenter();
                    auto distanceMagnitude = std::sqrtf(std::powf(distance.x, 2) + std::powf(distance.y, 2));

                    if (distanceMagnitude < body.getDiameter()) {
                        auto overlapMagnitude = body.getDiameter() - distanceMagnitude;

                        body.m_force += distance * overlapMagnitude * 0.5f;
                        body.m_position += body.m_force * deltaTime;
                        neighbourBody.m_force += -distance * overlapMagnitude * 0.5f;
                        neighbourBody.m_position += neighbourBody.m_force * deltaTime;
                    }
                }
            }

            body.m_force = {body.m_force.x, body.m_force.y + World::gravity * World::worldMultiplier * deltaTime};

            body.m_position += body.m_force * deltaTime;
            entity.updatePosition();
        } else {
            body.m_force = {0.0f, 0.0f};
        }
    }
}

sf::Vector2f Engine::getDistanceCircles(const sf::Vector2f &firsVector, const sf::Vector2f &secondVector) {

}