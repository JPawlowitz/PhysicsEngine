//
// Created by Jan Pawlowitz on 06.03.23.
//

#ifndef PHYSICSENGINE_MATH_H
#define PHYSICSENGINE_MATH_H

#include <cmath>
#include <string>

namespace math {
    //Constants
    static constexpr float PI{3.1415926535897932384626433832795};
    static constexpr float E{2.718281828459045235360287471352};

    static constexpr float GRAVITY_EARTH{9.80665};
    static constexpr float GRAVITY_MOON{0.0253};
    static constexpr float GRAVITY_MARS{3.72076};

    //Utility Functions
    template <typename T>
    static constexpr T RadToDeg(T angleRad) {
        return (angleRad * 180.0) / PI;
    }

    template <typename T>
    static constexpr auto DegToRad(T angleDeg) {
        return angleDeg * (180.0 / PI);
    }

    template <typename T>
    static constexpr T Clamp(T min, T max, T value) {
        if (value < min) { return min; }
        if (value > max) { return max; }
        return value;
    }

    template <typename T, typename U>
    static constexpr auto Lerp(T a, T b, U t) {
        return ((1 - t) * a) + (t * b);
    }

    template <typename T>
    static constexpr auto InvLerp(T a, T b, T value) {
        const auto t = (value - a) / (b - a);
        return Clamp(0.0f, 1.0f, t);
    }

    template <typename T>
    static constexpr T Remap(T iMin, T iMax, T oMin, T oMax, T value) {
        const auto t = InvLerp(iMin, iMax, value);
        return Lerp(oMin, oMax, t);
    }

    //Two-Dimensional float Vector
    struct Vec2 {
        Vec2() = default;
        Vec2(float x, float y) : x{x}, y{y} {};

        float x, y;

        void Set(float X, float Y) {
            x = X;
            y = Y;
        }

        float GetMagnitude() const {
            return std::hypot(x, y);
        }

        void Normalize() {
            *this /= GetMagnitude();
        }

        void SetMagnitude(float m) {
            this->Normalize();
            *this *= m;
        }

        void ClampMagnitude(float max) {
            if (this->GetMagnitude() > max) {
                this->SetMagnitude(max);
            }
        }

        float GetDotProduct(const Vec2& v) const {
            return (x * v.x) + (y * v.y);
        }

//        Vec2 getCrossProduct(const Vec2& v) const {
//
//        }

        float GetDistanceBetween(const Vec2& v) const {
            Vec2 normal = v - *this;
            return normal.GetMagnitude();
        }

        float GetAngleBetween(const Vec2& v) const {
            const auto phi = (GetDotProduct(v) / (GetMagnitude() * v.GetMagnitude()));
            return std::acos(phi);
        }

        float GetAngle() const {
            if (x >= 0.0f) {
                if (y >= 0.0f) { return std::atan(y / x); }
                return -std::atan(std::abs(y / x));
            } else {
                if (y >= 0.0f) { return PI - std::atan(std::abs(y / x)); };
                return std::atan(std::abs(y / x)) - PI;
            }
        }

        Vec2 LerpBetween(const Vec2& v, float t) const {
            const auto X = ((1.0f - t) * x) + (t * v.x);
            const auto Y = ((1.0f - t) * y) + (t * v.y);
            return Vec2{X, Y};
        }

        std::string ToString() const {
            return std::string{"(" + std::to_string(x) + " : " + std::to_string(y) + ")"};
        }

        Vec2& operator+= (const Vec2& v) {x += v.x; y += v.y; return *this;}
        Vec2& operator-= (const Vec2& v) {x -= v.x; y -= v.y; return *this;}
        Vec2& operator*= (const Vec2& v) {x *= v.x; y *= v.y; return *this;}
        Vec2& operator*= (float f) {x *= f; y *= f; return *this;}
        Vec2& operator/= (const Vec2& v) {x /= v.x; y /= v.y; return *this;}
        Vec2& operator/= (float f) {x /= f; y /= f; return *this;}
        Vec2& operator- () {x = -x; y = -y; return *this;}

        Vec2 operator+ (const Vec2& v) const { return Vec2{x,y} += v; }
        Vec2 operator- (const Vec2& v) const { return Vec2{x,y} -= v; }
        Vec2 operator* (const Vec2& v) const { return Vec2{x,y} *= v; }
        Vec2 operator* (float f) const { return Vec2{x,y} *= f; }
        Vec2 operator/ (const Vec2& v) const { return Vec2{x,y} /= v; }
        Vec2 operator/ (float f) const { return Vec2{x,y} /= f; }
        bool operator== (const Vec2 v) const { return x == v.x && y == v.y; }
        bool operator!= (const Vec2 v) const { return x != v.x | y != v.y; }
    };
}

#endif //PHYSICSENGINE_MATH_H
