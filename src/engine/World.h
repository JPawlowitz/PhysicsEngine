//
// Created by Jan Pawlowitz on 16.04.23.
//

#include "CircleBody.h"
#include <SFML/Graphics.hpp>
#include <vector>

#ifndef PHYSICSENGINE_WORLD_H
#define PHYSICSENGINE_WORLD_H

class World {
public:
    explicit World(int num_bodies);

    void Update();

private:
    std::vector<CircleBody> m_bodies;
    sf::VertexArray m_vertex_array;
};


#endif //PHYSICSENGINE_WORLD_H
