//
// Created by Jan Pawlowitz on 19.02.23.
//

#include "Vector2.h"

Vector2::Vector2(float x, float y) {
    m_x = x;
    m_y = y;
}

void Vector2::setVector(float x, float y) {
    m_x = x;
    m_y = y;
}

void Vector2::setX(float x) {
    m_x = x;
}

void Vector2::setY(float y) {
    m_y = y;
}