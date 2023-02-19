cmake_minimum_required(VERSION 3.24)
project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(PhysicsEngine src/main.cpp src/App.h src/App.cpp src/Engine/Engine.cpp src/Engine/Engine.h src/Engine/Bodies/PhysicsBody.cpp src/Engine/Bodies/PhysicsBody.h src/Engine/Math/Constants.h src/Engine/World.cpp src/Engine/World.h src/Engine/BodySpawner.cpp src/Engine/BodySpawner.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PhysicsEngine ${SFML_LIBRARIES})
    endif()