cmake_minimum_required(VERSION 3.24)
project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(PhysicsEngine src/main.cpp src/App.h src/App.cpp src/gui/ColorPalette.h src/libs/Math.h src/libs/Noise.h src/engine/Body.cpp src/engine/Body.h src/engine/CircleBody.cpp src/engine/CircleBody.h src/engine/World.cpp src/engine/World.h src/engine/Solver.cpp src/engine/Solver.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PhysicsEngine ${SFML_LIBRARIES})
    endif()