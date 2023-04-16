//
// Created by Jan Pawlowitz on 18.02.23.
//

#ifndef PHYSICSENGINE_APP_H
#define PHYSICSENGINE_APP_H

#include <SFML/Graphics.hpp>
#include <array>
#include <memory>

class App {
public:
    App(int width, int height);
    ~App() = default;

    const int c_width{};
    const int c_height{};

    void Start();
    void Run();
    void Draw();

    float getElapsedTime() const { return appClock.getElapsedTime().asSeconds(); }

private:
    sf::RenderWindow m_window;
    sf::Clock appClock{};

    float m_dt{};
};

#endif //PHYSICSENGINE_APP_H
