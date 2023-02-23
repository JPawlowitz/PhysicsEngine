//
// Created by Jan Pawlowitz on 19.02.23.
//

#include "Engine.h"
#include "./Math/Constants.h"
#include <cmath>

namespace Engine  {
    Engine::Engine(float width, float height, std::vector<World::Entity>* entities) : m_width{width}, m_height{height} {
        m_entities = entities;
    }

    void Engine::calculatePhysics(float deltaTime) {
        const float subDeltaTime = deltaTime / c_substeps;

        for (int i = 0; i < c_substeps; ++i) {
            m_grid.updateGrid();

            for (auto& entity : *m_entities) {
                auto& body = entity.m_body;

                checkBounds(body);
                checkCollisions(body, subDeltaTime);
                applyAcceleration(body, subDeltaTime);
            }

//            for (int y = 1; y < c_numCells - 1; ++y) {
//                for (int x = 1; x < c_numCells - 1; ++x) {
//                    for (int yNeighbour = -1; yNeighbour <= 1; ++yNeighbour) {
//                        for (int xNeighbour = -1; xNeighbour <=1; ++xNeighbour) {
//                            for (auto firstBody : m_grid[y][x]->bodies) {
//                                for (auto secondBody : m_grid[yNeighbour][xNeighbour]->bodies) {
//                                    if (firstBody->getIndex() != secondBody->getIndex()) {
//                                        checkCollision(*firstBody, *secondBody, subDeltaTime);
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//            }
        }



        for (auto& entity : *m_entities) {
            entity.updatePosition();
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

    void Engine::checkCollision(Body &firstBody, Body &secondBody, float deltaTime) {
        auto distance = firstBody.m_currentPosition - secondBody.m_currentPosition;
        auto distanceMagnitude = std::sqrtf((distance.x * distance.x) + (distance.y * distance.y));
        auto diameter = firstBody.getRadius() + secondBody.getRadius();

        if (distanceMagnitude < diameter) {
            auto overlapMagnitude = (diameter - distanceMagnitude) * 0.5f;

            firstBody.m_currentPosition += distance * overlapMagnitude * deltaTime;
            secondBody.m_currentPosition += -distance * overlapMagnitude * deltaTime;
        }
    }

    void Engine::checkCollisions(Body &body, float deltaTime) {
        for (auto& neighbour : *m_entities) {
            auto& neighbourBody = neighbour.m_body;

            auto distance = body.m_currentPosition - neighbourBody.m_currentPosition;
            auto distanceMagnitude = std::sqrtf((distance.x * distance.x) + (distance.y * distance.y));
            auto diameter = body.getRadius() + neighbourBody.getRadius();

            if (distanceMagnitude < diameter) {
                auto overlapMagnitude = (diameter - distanceMagnitude) * 0.5f;

                body.m_currentPosition += distance * overlapMagnitude * deltaTime;
                neighbourBody.m_currentPosition += -distance * overlapMagnitude * deltaTime;
            }
        }
    }

//    void Engine::checkCollisions(float deltaTime) {
//        for (int y = 0; y < c_numCells - 1; ++y) {
//            for (int x = 0; x < c_numCells - 1; ++x) {
//                for (auto& index : m_grid[y][x]) {
//                    auto& body = m_entities->at(index).m_body;
//
//                    for (auto& neighbourIndex : m_grid[y][x]) {
//                        auto& neighbourBody = m_entities->at(neighbourIndex).m_body;
//
//                        auto distance = body.m_currentPosition - neighbourBody.m_currentPosition;
//                        auto distanceMagnitude = std::sqrtf((distance.x * distance.x) + (distance.y * distance.y));
//                        auto diameter = body.getRadius() + neighbourBody.getRadius();
//
//                        if (distanceMagnitude < diameter) {
//                            auto overlapMagnitude = (diameter - distanceMagnitude) * 0.5f;
//
//                            body.m_currentPosition += distance * overlapMagnitude * deltaTime;
//                            neighbourBody.m_currentPosition += -distance * overlapMagnitude * deltaTime;
//                        }
//                    }
//                }
//            }
//        }
//    }

    void Engine::applyAcceleration(Body &body, float subDeltaTime) {
        body.m_acceleration += {0.0f, body.getMass() * World::gravity};
        body.m_velocity = body.m_currentPosition - body.m_previousPosition;

        body.m_previousPosition = body.m_currentPosition;
        body.m_currentPosition += body.m_velocity + body.m_acceleration * subDeltaTime * subDeltaTime;

        body.m_acceleration = {};
    }
}
