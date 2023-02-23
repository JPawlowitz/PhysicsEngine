//
// Created by Jan Pawlowitz on 23.02.23.
//

#include "Grid.h"

namespace Engine {
    World::Chunk &Engine::Grid::getChunk(int y, int x) {
        return m_chunks[y][x];
    }

    void Engine::Grid::updateGrid() {

    }
}