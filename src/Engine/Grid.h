//
// Created by Jan Pawlowitz on 23.02.23.
//

#ifndef PHYSICSENGINE_GRID_H
#define PHYSICSENGINE_GRID_H

#include "Chunk.h"
#include <array>

namespace Engine {
    class Grid {
    public:
        Grid() = default;
        ~Grid() = default;

        World::Chunk& getChunk(int y, int x);
        void updateGrid();

    private:
        static const unsigned int c_numCells{50};

        std::array<std::array<World::Chunk, c_numCells>, c_numCells> m_chunks{};
    };
}

#endif //PHYSICSENGINE_GRID_H
