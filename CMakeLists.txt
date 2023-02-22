cmake_minimum_required(VERSION 3.24)
project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(PhysicsEngine src/main.cpp src/App.h src/App.cpp src/Engine/Engine.cpp src/Engine/Engine.h src/Engine/Math/Constants.h src/World/World.cpp src/World/World.h src/World/BodySpawner.cpp src/World/BodySpawner.h src/World/Entity.cpp src/World/Entity.h src/Engine/Bodies/Body.cpp src/Engine/Bodies/Body.h src/Engine/Math/Vector2.cpp src/Engine/Math/Vector2.h src/World/ColorPalette.h src/World/Chunk.cpp src/World/Chunk.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PhysicsEngine ${SFML_LIBRARIES})
    endif()