#pragma once

#include <cstdint>
#include <functional>

template<typename D>
struct Vec2
{
    D x, y;

    constexpr inline Vec2(D x, D y) : x(x), y(y) {}
    constexpr inline Vec2() : x(0), y(0) {}

    template<typename F>
    constexpr inline operator Vec2<F>() const
    {
        return Vec2<F>{(F)x, (F)y};
    }

    constexpr Vec2 operator+(const Vec2& other) const;
    constexpr Vec2 operator-(const Vec2& other) const;
    constexpr Vec2 operator*(D scale) const;
    constexpr Vec2 operator/(D scale) const;

    constexpr Vec2& operator+=(const Vec2& other);
    constexpr Vec2& operator-=(const Vec2& other);
    constexpr Vec2& operator*=(D scale);
    constexpr Vec2& operator/=(D scale);

    constexpr float Length() const;
    constexpr float Dot(const Vec2& other) const;
    constexpr Vec2 Normalize() const;

    constexpr D Min() const;
    constexpr D Max() const;

    constexpr bool operator==(const Vec2& other) const;
    constexpr bool operator!=(const Vec2& other) const;
    constexpr bool operator<(const Vec2& other) const;
    constexpr bool operator>(const Vec2& other) const;
    constexpr bool operator<=(const Vec2& other) const;
    constexpr bool operator>=(const Vec2& other) const;
};

template<typename D>
constexpr Vec2<D> operator*(D scale, const Vec2<D>& vec);
template<typename D>
constexpr Vec2<D> operator/(D scale, const Vec2<D>& vec);

template<typename D>
struct std::hash<Vec2<D>>
{
    constexpr size_t operator()(const Vec2<D>& key) const;
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