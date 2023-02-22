//
// Created by Jan Pawlowitz on 22.02.23.
//

#include "Vector2.h"
#include <cmath>

float Vector2::getMagnitude() const {
    return std::sqrtf((x * x) + (y * y));
}