#pragma once

#include <cstdint>
#include <functional>

template<typename D>
struct Vec4
{

    D x, y, z, w;

    constexpr inline Vec4(D x, D y, D z, D w) : x(x), y(y), z(z), w(w) {}
    constexpr inline Vec4() : x(0), y(0), z(0), w(0) {}
    constexpr explicit inline Vec4(D v) : x(v), y(v), z(v), w(v) {}

    template<typename F>
    constexpr inline operator Vec4<F>() const
    {
        return Vec4<F>{(F)x, (F)y, (F)z, (F)w};
    }

    constexpr Vec4 operator+(const Vec4& other) const;
    constexpr Vec4 operator-(const Vec4& other) const;
    constexpr Vec4 operator*(const Vec4& other) const;
    constexpr Vec4 operator/(const Vec4& other) const;
    constexpr Vec4 operator*(D scale) const;
    constexpr Vec4 operator/(D scale) const;

    constexpr Vec4& operator+=(const Vec4& other);
    constexpr Vec4& operator-=(const Vec4& other);
    constexpr Vec4& operator*=(const Vec4& other);
    constexpr Vec4& operator/=(const Vec4& other);
    constexpr Vec4& operator*=(D scale);
    constexpr Vec4& operator/=(D scale);

    constexpr float Length() const;
    constexpr float Dot(const Vec4& other) const;
    constexpr Vec4 Normalize() const;

    constexpr D Min() const;
    constexpr D Max() const;

    constexpr bool operator==(const Vec4& other) const;
    constexpr bool operator!=(const Vec4& other) const;
    constexpr bool operator<(const Vec4& other) const;
    constexpr bool operator>(const Vec4& other) const;
    constexpr bool operator<=(const Vec4& other) const;
    constexpr bool operator>=(const Vec4& other) const;
};

template<typename D>
constexpr Vec4<D> operator*(D scale, const Vec4<D>& vec);
template<typename D>
constexpr Vec4<D> operator/(D scale, const Vec4<D>& vec);

template<typename D>
struct std::hash<Vec4<D>>
{
    constexpr size_t operator()(const Vec4<D>& key) const;
};

#include "math/Vec4.tpp"

typedef Vec4<float> Vec4f;
typedef Vec4<double> Vec4d;
typedef Vec4<int8_t> Vec4i8;
typedef Vec4<uint8_t> Vec4u8;
typedef Vec4<int16_t> Vec4i16;
typedef Vec4<uint16_t> Vec4u16;
typedef Vec4<int32_t> Vec4i32;
typedef Vec4<uint32_t> Vec4u32;
typedef Vec4<int64_t> Vec4i64;
typedef Vec4<uint64_t> Vec4u64;