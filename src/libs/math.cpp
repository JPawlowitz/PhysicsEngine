//
// Created by Jan Pawlowitz on 16.04.23.
//

export module math;

import <cmath>;
import <string>;

export namespace math {
    //Constants
    float PI{3.1415926535897932384626433832795};
    float E{2.718281828459045235360287471352};

    float GRAVITY_EARTH{9.80665};
    float GRAVITY_MOON{0.0253};
    float GRAVITY_MARS{3.72076};

    //Utility Functions
    template <typename T>
    T radToDeg(T angleRad) {
        return (angleRad * 180.0) / PI;
    }

    template <typename T>
    auto degToRad(T angleDeg) {
        return angleDeg * (180.0 / PI);
    }

    template <typename T>
    T clamp(T min, T max, T value) {
        if (value < min) { return min; }
        if (value > max) { return max; }
        return value;
    }

    template <typename T, typename U>
    auto lerp(T a, T b, U t) {
        return ((1 - t) * a) + (t * b);
    }

    template <typename T>
    auto invLerp(T a, T b, T value) {
        const auto t = (value - a) / (b - a);
        return clamp(0.0f, 1.0f, t);
    }

    template <typename T>
    T remap(T iMin, T iMax, T oMin, T oMax, T value) {
        const auto t = invLerp(iMin, iMax, value);
        return lerp(oMin, oMax, t);
    }

    //Two-Dimensional float Vector
    struct Vec2 {
        Vec2() = default;
        Vec2(float x, float y) : x{x}, y{y} {};

        float x, y;

        float getMagnitude() const {
            return std::hypot(x, y);
        }

        void normalize() {
            *this /= getMagnitude();
        }

        void setMagnitude(float m) {
            this->normalize();
            *this *= m;
        }

        void clampMagnitude(float max) {
            if (this->getMagnitude() > max) {
                this->setMagnitude(max);
            }
        }

        float getDotProduct(const Vec2& v) const {
            return (x * v.x) + (y * v.y);
        }

//        Vec2 getCrossProduct(const Vec2& v) const {
//
//        }

        float getDistanceBetween(const Vec2& v) const {
            Vec2 normal = v - *this;
            return normal.getMagnitude();
        }

        float getAngleBetween(const Vec2& v) const {
            const auto phi = (getDotProduct(v) / (getMagnitude() * v.getMagnitude()));
            return std::acos(phi);
        }

        float getAngle() const {
            if (x >= 0.0f) {
                if (y >= 0.0f) { return std::atan(y / x); }
                return -std::atan(std::abs(y / x));
            } else {
                if (y >= 0.0f) { return PI - std::atan(std::abs(y / x)); };
                return std::atan(std::abs(y / x)) - PI;
            }
        }

        Vec2 lerpBetween(const Vec2& v, float t) const {
            const auto X = ((1.0f - t) * x) + (t * v.x);
            const auto Y = ((1.0f - t) * y) + (t * v.y);
            return Vec2{X, Y};
        }

        void rotateEuler(float angle) {

        }

        std::string toString() const {
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