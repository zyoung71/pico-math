#include <pico/stdlib.h>
#include <stdio.h>

#include <math/Quat.h>
#include <math/Easing.h>
#include <math/Vec3.h>
#include <math/AABB.h>

consteval Vec2f test()
{
    Vec2f v{4.f, 3.f};
    v *= 3.f;
    v *= Vec2f{3, 3};
    return Vec2f::Round(v);
}

int main()
{
    Quatf q;
    Vec3u32 v;

    Vec3f v2 = (Vec3f)v;

    Vec2u32 l;
    AABBi32 aabb;

    Vec2f vf = test();
    Vec2d vd;
    vf = Vec2f(1.f);

    auto vfl = vf.Length();
    auto vdl = vd.Length();

    aabb.vec.w;
    size_t idx = 0;
    while (1)
    {
        printf("Sine In Out Table at index %u:\t%f", idx, easing::lut_sine_in_out[idx]);
        if (++idx == 256)
            idx = 0;
        tight_loop_contents();
    }

}