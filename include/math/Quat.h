#pragma once

#include <cstdint>

template<typename D>
struct Quat
{
    D w, x, y, z;

    constexpr inline Quat() : w((D)1.0), x((D)0.0), y((D)0.0), z((D)0.0) {}
    constexpr inline Quat(D w, D x, D y, D z) : w(w), x(x), y(y), z(z) {}

    float Magnitude() const;
    Quat Normalize() const;
    Quat Inverse() const;
    Quat Conjugate() const;

    Quat operator*(D scale) const;
    Quat operator*(const Quat& other) const;
    Quat operator/(D scale) const;
    Quat operator/(const Quat& other) const;
    Quat& operator*=(D scale);
    Quat& operator*=(const Quat& other);
    Quat& operator/=(D scale);
    Quat& operator/=(const Quat& other);

    Quat operator-() const;

    Quat& operator++();
    Quat& operator--();
    Quat operator++(int);
    Quat operator--(int);

    bool operator==(const Quat& other) const;
    bool operator!=(const Quat& other) const;
};

#include "math/Quat.tpp"

typedef Quat<float> Quatf;
typedef Quat<double> Quatd;
typedef Quat<int8_t> Quati8;
typedef Quat<uint8_t> Quatu8;
typedef Quat<int16_t> Quati16;
typedef Quat<uint16_t> Quatu16;
typedef Quat<int32_t> Quati32;
typedef Quat<uint32_t> Quatu32;
typedef Quat<int64_t> Quati64;
typedef Quat<uint64_t> Quatu64;