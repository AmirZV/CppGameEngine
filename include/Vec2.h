//
// Created by AmirZ on 11/20/2025.
//

#ifndef CPPGAMEENGINE_VEC2_H
#define CPPGAMEENGINE_VEC2_H

#include <cmath>

namespace zv
{

struct Vec2
{
    float x{};
    float y{};

    // Constructors
    constexpr Vec2() = default;

    constexpr Vec2(const float x, const float y) : x{x}, y{y}
    {
    }

    // Arithmetic operators
    [[nodiscard]] constexpr Vec2 operator+(const Vec2& rhs) const noexcept { return {x + rhs.x, y + rhs.y}; }
    [[nodiscard]] constexpr Vec2 operator-(const Vec2& rhs) const noexcept { return {x - rhs.x, y - rhs.y}; }
    [[nodiscard]] constexpr Vec2 operator*(const float scalar) const noexcept { return {x * scalar, y * scalar}; }

    [[nodiscard]] constexpr friend Vec2 operator*(const float scalar, const Vec2& v) noexcept
    {
        return {v.x * scalar, v.y * scalar};
    }

    // Compound assignment
    Vec2& operator+=(const Vec2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    Vec2& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    // Comparison
    constexpr bool operator==(const Vec2& rhs) const noexcept { return x == rhs.x && y == rhs.y; }
    constexpr bool operator!=(const Vec2& rhs) const noexcept { return !(*this == rhs); }

    // Vector utilities
    [[nodiscard]] constexpr float dot(const Vec2& rhs) const noexcept { return x * rhs.x + y * rhs.y; }
    [[nodiscard]] float length() const noexcept { return std::sqrt(x * x + y * y); }

    [[nodiscard]] Vec2 normalized() const noexcept
    {
        const float len = length();
        return len != 0 ? Vec2{x / len, y / len} : Vec2{0, 0};
    }

    [[nodiscard]] constexpr float cross(const Vec2& rhs) const noexcept { return x * rhs.y - y * rhs.x; }
};

}

#endif //CPPGAMEENGINE_VEC2_H
