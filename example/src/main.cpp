#include <pico/stdlib.h>
#include <stdio.h>

#include <math/Quat.h>
#include <math/Graphics.h>
#include <math/Vec3.h>
#include <math/AABB.h>

int main()
{
    Quatf q;
    Vec3u32 v;

    Vec3f v2 = (Vec3f)v;

    Vec2u32 l;
    AABBi32 aabb;

    graphics::scanline_rasterization<uint32_t>(nullptr, 0, nullptr, nullptr); // empty

    size_t idx = 0;
    while (1)
    {
        printf("Sine In Out Table at index %u:\t%f", idx, graphics::easing::lut_sine_in_out[idx]);
        if (++idx == 256)
            idx = 0;
        tight_loop_contents();
    }

}