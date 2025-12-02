#pragma once

#include "Vec2.h"

namespace graphics
{
    typedef void (*DrawCallback)(Vec2u32 pixel);
    
    template<typename D>
    void scanline_rasterization(const Vec2<D>* points, size_t points_count, DrawCallback callback);
}
#include <math/Graphics.tpp>