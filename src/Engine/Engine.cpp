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
    const int substeps = 4;
    const float subDeltaTime = deltaTime / substeps;

    for (int i = 0; i < substeps; ++i) {
        for (auto& entity : *entities) {
            auto& body = entity.m_body;

            checkBounds(body);
            checkCollisions(body, entities);
            applyAcceleration(body, subDeltaTime);

            entity.updatePosition();
        }
    }

}

void Engine::checkBounds(Body &body) const {
    if (body.m_currentPosition.x - body.getRadius() < 0.0f) {
        body.m_currentPosition.x = body.getRadius();
    }

    if (body.m_currentPosition.x + body.getRadius() > m_width) {
        body.m_currentPosition.x = m_width - body.getRadius();
    }

    if (body.m_currentPosition.y + body.getRadius() > m_height) {
        body.m_currentPosition.y = m_height - body.getRadius();
    }
}

void Engine::checkCollisions(Body &body, std::vector<World::Entity> *entities) {
    for (auto& neighbour : *entities) {
        auto& neighbourBody = neighbour.m_body;

        auto distance = body.m_currentPosition - neighbourBody.m_currentPosition;
        auto distanceMagnitude = std::sqrtf((distance.x * distance.x) + (distance.y * distance.y));
        auto diameter = body.getRadius() + neighbourBody.getRadius();

        if (distanceMagnitude < diameter) {
            auto overlapMagnitude = diameter - distanceMagnitude;

            body.m_currentPosition += distance * overlapMagnitude * 0.0001f;
            neighbourBody.m_currentPosition += -distance * overlapMagnitude * 0.0001f;
        }
    }
}

void Engine::applyAcceleration(Body &body, float subDeltaTime) {
    body.m_acceleration += {0.0f, body.getMass() * World::gravity};
    body.m_velocity = body.m_currentPosition - body.m_previousPosition;

    body.m_previousPosition = body.m_currentPosition;
    body.m_currentPosition += body.m_velocity + body.m_acceleration * subDeltaTime * subDeltaTime;

    body.m_acceleration = {};
}