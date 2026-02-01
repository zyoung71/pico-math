#pragma once

#include "Vec2.h"

template<typename D>
struct AABB
{
    union
    {
        struct
        {
            D xmin, ymin;
        }; 
        Vec2<D> min;
    };
    union
    {
        struct
        {
            D xmax, ymax;
        };
        Vec2<D> max;
    };

    constexpr inline AABB(const Vec2<D>& min, const Vec2<D>& max) : min(min), max(max) {}
    constexpr inline AABB(D xmin, D ymin, D xmax, D ymax) : xmin(xmin), ymin(ymin), xmax(xmax), ymax(ymax) {}
    constexpr inline AABB() : xmin(0), ymin(0), xmax(1), ymax(1) {}

    bool Intersects(const AABB& other) const;
};
#include <math/AABB.tpp>

typedef AABB<float> AABBf;
typedef AABB<double> AABBd;
typedef AABB<int8_t> AABBi8;
typedef AABB<uint8_t> AABBu8;
typedef AABB<int16_t> AABBi16;
typedef AABB<uint16_t> AABBu16;
typedef AABB<int32_t> AABBi32;
typedef AABB<uint32_t> AABBu32;
typedef AABB<int64_t> AABBi64;
typedef AABB<uint64_t> AABBu64;