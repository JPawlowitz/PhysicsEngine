//
// Created by Jan Pawlowitz on 19.02.23.
//

#include "Engine.h"
#include "./Math/Constants.h"

Engine::Engine(float groundLevel) : m_groundLevel(groundLevel){}

void Engine::addBody(const PhysicsBody &newBody) {
    m_bodies.push_back(newBody);
}

std::vector<PhysicsBody>& Engine::getBodies() {
    return m_bodies;
}

void Engine::runSimulation(float deltaTime) {
    for (auto& body : m_bodies) {
        if (body.getShape().getPosition().y + body.getShape().getLocalBounds().height < m_groundLevel) {
            body.setAcceleration(sf::Vector2f {body.getAcceleration().x, body.getAcceleration().y + math::gravity * deltaTime});
            body.updatePosition(deltaTime);
        } else {
            body.setAcceleration(sf::Vector2f{});
        }
    }
}