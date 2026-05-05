#pragma once

#include "Vec2.h"
#include <type_traits>

template<typename D>
struct OBB
{
    using FloatType = std::conditional_t<sizeof(D) >= 8, double, float>;

    Vec2<D> center;
    Vec2<D> half_size;
    FloatType rotation; // radians
};

typedef OBB<float> OBBf;
typedef OBB<double> OBBd;
typedef OBB<int8_t> OBBi8;
typedef OBB<uint8_t> OBBu8;
typedef OBB<int16_t> OBBi16;
typedef OBB<uint16_t> OBBu16;
typedef OBB<int32_t> OBBi32;
typedef OBB<uint32_t> OBBu32;
typedef OBB<int64_t> OBBi64;
typedef OBB<uint64_t> OBBu64;