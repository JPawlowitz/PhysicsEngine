//
// Created by Jan Pawlowitz on 18.02.23.
//

#ifndef PHYSICSENGINE_APP_H
#define PHYSICSENGINE_APP_H

class App {
public:
    App() = default;
    ~App() = default;

    void run();

private:
    float m_deltaTime{};
};

#endif //PHYSICSENGINE_APP_H