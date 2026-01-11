#include <pico/stdlib.h>
#include <stdio.h>

#include <math/Quat.h>
#include <math/Graphics.h>

int main()
{

    Quatf q;

    graphics::scanline_rasterization<uint32_t>(nullptr, 0, nullptr, nullptr); // empty

    while (1)
    {
        tight_loop_contents();
    }

}