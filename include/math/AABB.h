#pragma once

template<typename D>
struct AABB
{
    D xmin, ymin, xmax, ymax;

    constexpr inline AABB(D xmin, D ymin, D xmax, D ymax) : xmin(xmin), ymin(ymin), xmax(xmax), ymax(ymax) {}
    constexpr inline AABB() : xmin(0), ymin(0), xmax(1), ymax(1) {}

    bool Intersects(const AABB& other) const;
};
#include <math/AABB.tpp>