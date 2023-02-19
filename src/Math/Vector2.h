//
// Created by Jan Pawlowitz on 19.02.23.
//

#ifndef PHYSICSENGINE_VECTOR2_H
#define PHYSICSENGINE_VECTOR2_H


class Vector2 {
public:
    Vector2(float x, float y);
    ~Vector2() = default;

    float getX() const { return m_x; }
    float getY() const { return m_y; }

    void setVector(float x, float y);
    void setX(float x);
    void setY(float y);

private:
    float m_x{};
    float m_y{};
};


#endif //PHYSICSENGINE_VECTOR2_H
