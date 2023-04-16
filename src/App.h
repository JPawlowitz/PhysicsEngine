//
// Created by Jan Pawlowitz on 18.02.23.
//

#ifndef PHYSICSENGINE_APP_H
#define PHYSICSENGINE_APP_H

#include "./gui/Window.h"
#include "./engine/PhysicsEngine.h"
#include "./engine/Spawner.h"
#include <SFML/Graphics.hpp>
#include <array>
#include <memory>

class App {
public:
    App(int width, int height, const Solver::SolverType& solverType);
    ~App() = default;

    const int c_width{};
    const int c_height{};

    void start();
    void run();
    float getElapsedTime() const { return appClock.getElapsedTime().asSeconds(); }

private:
    std::unique_ptr<PhysicsEngine> m_engine;
    std::unique_ptr<Window> m_window;
    std::unique_ptr<Spawner> m_spawner;

    sf::Clock appClock{};

    float m_dt{};
};

#endif //PHYSICSENGINE_APP_H
