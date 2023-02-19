cmake_minimum_required(VERSION 3.24)
project(PhysicsEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(PhysicsEngine src/main.cpp src/App.h src/App.cpp src/Engine.cpp src/Engine.h src/Shapes/PhysicsBody.cpp src/Shapes/PhysicsBody.h src/Math/Constants.h src/Math/Vector2.cpp src/Math/Vector2.h)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PhysicsEngine ${SFML_LIBRARIES})
    endif()