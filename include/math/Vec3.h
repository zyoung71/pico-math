#pragma once

#include <cstdint>

template<typename D>
struct Vec3
{

    D x, y, z;

    constexpr Vec3(D x, D y, D z) : x(x), y(y), z(z) {}
    constexpr Vec3() : x(0), y(0), z(0) {}

    template<typename F>
    inline operator Vec3<F>() const
    {
        return Vec3<F>{(F)x, (F)y, (F)z};
    }

    Vec3 operator+(const Vec3& other) const;
    Vec3 operator-(const Vec3& other) const;
    Vec3 operator*(D scale) const;
    Vec3 operator/(D scale) const;

    Vec3& operator+=(const Vec3& other);
    Vec3& operator-=(const Vec3& other);
    Vec3& operator*=(D scale);
    Vec3& operator/=(D scale);

    float Length() const;
    float Dot(const Vec3& other) const;

    Vec3 Normalize() const;
    Vec3 Cross(const Vec3& other) const;
};

#include "math/Vec3.h"

typedef Vec3<float> Vec3f;
typedef Vec3<double> Vec3d;
typedef Vec3<int8_t> Vec3i8;
typedef Vec3<uint8_t> Vec3u8;
typedef Vec3<int16_t> Vec3i16;
typedef Vec3<uint16_t> Vec3u16;
typedef Vec3<int32_t> Vec3i32;
typedef Vec3<uint32_t> Vec3u32;
typedef Vec3<int64_t> Vec3i64;
typedef Vec3<uint64_t> Vec3u64;