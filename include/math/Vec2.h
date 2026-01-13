#pragma once

#include <cstdint>

template<typename D>
struct Vec2
{
    D x, y;

    constexpr inline Vec2(D x, D y) : x(x), y(y) {}
    constexpr inline Vec2() : x(0), y(0) {}

    template<typename F>
    inline operator Vec2<F>() const
    {
        return Vec2<F>{(F)x, (F)y};
    }

    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& other) const;
    Vec2 operator*(D scale) const;
    Vec2 operator/(D scale) const;

    Vec2& operator+=(const Vec2& other);
    Vec2& operator-=(const Vec2& other);
    Vec2& operator*=(D scale);
    Vec2& operator/=(D scale);

    float Length() const;
    float Dot(const Vec2& other) const;
    Vec2 Normalize() const;
};

#include <math/Vec2.tpp>

typedef Vec2<float> Vec2f;
typedef Vec2<double> Vec2d;
typedef Vec2<int8_t> Vec2i8;
typedef Vec2<uint8_t> Vec2u8;
typedef Vec2<int16_t> Vec2i16;
typedef Vec2<uint16_t> Vec2u16;
typedef Vec2<int32_t> Vec2i32;
typedef Vec2<uint32_t> Vec2u32;
typedef Vec2<int64_t> Vec2i64;
typedef Vec2<uint64_t> Vec2u64;