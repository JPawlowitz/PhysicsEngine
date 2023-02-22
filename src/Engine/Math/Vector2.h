//
// Created by Jan Pawlowitz on 22.02.23.
//

#ifndef PHYSICSENGINE_VECTOR2_H
#define PHYSICSENGINE_VECTOR2_H


struct Vector2 {
    float x{};
    float y{};

    Vector2 operator+ (const Vector2& a) const { return Vector2{a.x + x, a.y + y}; }
    Vector2 operator- (const Vector2& a) const { return Vector2{a.x - x, a.y - y}; }
    Vector2 operator* (const float& a) const { return Vector2{x * a, y * a}; }

    float getMagnitude() const;
};


#endif //PHYSICSENGINE_VECTOR2_H
