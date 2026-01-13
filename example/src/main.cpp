#include <pico/stdlib.h>
#include <stdio.h>

#include <math/Quat.h>
#include <math/Graphics.h>
#include <math/Vec3.h>

int main()
{

    Quatf q;
    Vec3u32 v;

    Vec3f v2 = (Vec3f)v;

    graphics::scanline_rasterization<uint32_t>(nullptr, 0, nullptr, nullptr); // empty

    while (1)
    {
        tight_loop_contents();
    }

}