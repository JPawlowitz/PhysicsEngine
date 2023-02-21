//
// Created by Jan Pawlowitz on 19.02.23.
//

#include "Engine.h"
#include "./Math/Constants.h"
#include <cmath>

Engine::Engine(float width, float height) : m_width{width}, m_height{height} {}

//void Engine::calculatePhysics(float deltaTime, std::vector<World::Entity> *entities) {
//    for (auto& entity : *entities) {
//        auto& body = entity.m_body;
//
//        body.m_acceleration = { 0.0f, body.getMass() * World::gravity };
//
//        for (auto& neighbour : *entities) {
//            auto& neighbourBody = neighbour.m_body;
//
//            if (body.m_position != neighbourBody.m_position) {
//                auto distance = body.m_position - neighbourBody.m_position;
//                auto distanceMagnitude = std::sqrtf(std::powf(distance.x, 2) + std::powf(distance.y, 2));
//
//                if (distanceMagnitude < body.getDiameter()) {
//                    auto overlapMagnitude = body.getDiameter() - distanceMagnitude;
//
//                    body.m_velocity += distance * overlapMagnitude * World::collisionAbsorption * 0.1f;
//                }
//            }
//        }
//
//        checkBounds(body);
//
//        body.m_velocity += body.m_acceleration * deltaTime;
//
//        body.m_position += body.m_velocity * deltaTime;
//
//        entity.updatePosition();
//    }
//}

void Engine::calculatePhysics(float deltaTime, std::vector<World::Entity> *entities) {
    for (auto& entity : *entities) {

    }
}

void Engine::checkBounds(Body& body) const {
    //Left and right bounds
    if (body.m_position.x - body.getRadius() < 0.0f || body.m_position.x + body.getRadius() > m_width) {
        body.m_velocity = {-body.m_velocity.x * World::collisionAbsorption, body.m_velocity.y };
    }

    //Floor
    if (body.m_position.y + body.getRadius() >= m_height) {
        auto sign = body.m_velocity.x >= 0.0f ? -1.0f : 1.0f;
        body.m_acceleration.x += (body.getMass() * World::gravity * World::groundFriction) * sign;
        body.m_acceleration.y = 0.0f;

        body.m_velocity = {body.m_velocity.x, -body.m_velocity.y * World::collisionAbsorption};
    }
}

void Engine::checkCollision() {

}