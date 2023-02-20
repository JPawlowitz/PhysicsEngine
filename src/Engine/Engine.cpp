//
// Created by Jan Pawlowitz on 19.02.23.
//

#include "Engine.h"
#include "./Math/Constants.h"

Engine::Engine(int width, int height) : m_width{width}, m_height{height} {}

void Engine::calculatePhysics(float deltaTime, std::vector<World::Entity> *entities) {
    for (auto& entity : *entities) {
        auto& body = entity.m_body;

        if (body.m_position.y < m_height - body.getDiameter() * 2) {
            body.m_force = {body.m_force.x, body.m_force.y + World::gravity * World::worldMultiplier * deltaTime};

            body.m_position += body.m_force * deltaTime;
            entity.updatePosition();
        } else {
            body.m_force = {0.0f, 0.0f};
        }
    }
}