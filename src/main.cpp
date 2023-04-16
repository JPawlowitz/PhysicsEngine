#include "App.h"
#include "./libs/Math.h"
#include <iostream>

int main() {
    App app{1920, 1080, Solver::SolverType::Verlet};

    app.start();

    return 0;
}
