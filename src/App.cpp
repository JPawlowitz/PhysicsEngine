//
// Created by Jan Pawlowitz on 18.02.23.
//
#include "App.h"

App::App(int width, int height, const Solver::SolverType& solverType)
: c_width{width}, c_height{height} {
    m_engine = std::make_unique<PhysicsEngine>(solverType, math::Vec2{static_cast<float>(width), static_cast<float>(height)});
    m_window = std::make_unique<Window>(width, height);
    m_spawner = std::make_unique<Spawner>(*m_engine, math::Vec2{static_cast<float>(width - 10), 10.0f}, 200, 0.05f, 10.0f);
}

void App::start() {
    m_spawner->spawnEntityAt(math::Vec2{c_width / 2.0f, c_height / 2.0f}, math::Vec2{-20.0f, 0.0f}, 10.0f, 50.0f);
    m_spawner->spawnEntityAt(math::Vec2{c_width / 3.0f, c_height / 3.0f}, math::Vec2{20.0f, 0.0f}, 10.0f, 50.0f);

    run();
}

void App::run() {
    auto dtClock = sf::Clock{};

    while(m_window->isOpen()){
        m_spawner->update(m_dt);

        m_engine->update(m_dt);

        m_window->updateWindow(*m_engine->getBodies());

        m_dt = dtClock.restart().asSeconds();
    }
}
