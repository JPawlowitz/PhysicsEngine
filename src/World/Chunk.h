//
// Created by Jan Pawlowitz on 22.02.23.
//

#ifndef PHYSICSENGINE_CHUNK_H
#define PHYSICSENGINE_CHUNK_H

#include "../Engine/Bodies/Body.h"
#include <vector>

namespace World {

    class Chunk {
    public:
        Chunk() = default;
        ~Chunk() = default;

        std::vector<Body*> m_bodies{};
    };
}

#endif //PHYSICSENGINE_CHUNK_H
