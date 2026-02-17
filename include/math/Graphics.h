#pragma once

#include <array>
#include <cmath>
#include <numbers>

#include "Vec2.h"

namespace graphics
{
    typedef void (*DrawCallback)(Vec2i32, void*);
    
    template<typename D>
    void scanline_rasterization(const Vec2<D>* points, size_t points_count, DrawCallback callback, void* usr = nullptr);

    namespace easing
    {
        constexpr size_t lut_size = 256;
        typedef std::array<float, lut_size> FunctionLUT;

        typedef float(*LUTInit)(float);
        consteval FunctionLUT make_lut(LUTInit init_cb)
        {
            std::array<float, lut_size> lut;
            for (size_t i = 0; i < lut_size; i++)
            {
                float t = i / static_cast<float>(lut_size - 1);
                lut[i] = init_cb(t);
            }
            return lut;
        }

        /**
         * Easing functions obtained from https://easings.net
         */

        consteval float sine_in(float time)
        {
            return 1.f - std::cosf(std::numbers::pi * time * 0.5f);
        }

        consteval float sine_out(float time)
        {
            return std::sinf(std::numbers::pi * time * 0.5f);
        }

        consteval float sine_in_out(float time)
        {
            return -(std::cosf(std::numbers::pi * time) - 1.f) * 0.5f;
        }

        consteval float quad_in(float time)
        {
            return time * time;
        }

        consteval float quad_out(float time)
        {
            return time * (2.f - time);
        }

        consteval float quad_in_out(float time)
        {
            if (time < 0.5f)
                return 2.f * time * time;
            else
            {
                time -= 1.f;
                return -2.f * time * time + 1.f;
            }
        }

        consteval float cubic_in(float time)
        {
            return time * time * time;
        }

        consteval float cubic_out(float time)
        {
            time -= 1.f;
            return time * time * time + 1.f;
        }

        consteval float cubic_in_out(float time)
        {
            if (time < 0.5)
                return 4.f * time * time * time;
            else
            {
                float rtime = 2.f * time - 2.f;
                return 0.5f * rtime * rtime * rtime + 1.f;
            }
        }

        // define this first for the IN function below it
        consteval float bounce_out(float time)
        {
            constexpr float n1 = 7.5625f;
            constexpr float d1 = 2.75f;

            if (time < 1.f / d1)
                return n1 * time * time;
            else if (time < 2.f / d1)
            {
                time -= 1.5f / d1;
                return n1 * time * time + 0.75f;
            }
            else if (time < 2.5f / d1)
            {
                time -= 2.25f / d1;
                return n1 * time * time + 0.9375f;
            }
            else
            {
                time -= 2.625f / d1;
                return n1 * time * time + 0.984375f;
            }
        }

        consteval float bounce_in(float time)
        {
            return 1.f - bounce_out(1.f - time);
        }

        consteval float bounce_in_out(float time)
        {
            if (time < 0.5f)
                return 0.5f * (1.f - bounce_out(1.f - 2.f * time));
            else
                return 0.5f * bounce_out(2.f * time - 1.f) + 0.5f;
        }

        consteval float elastic_in(float time)
        {
            constexpr float c4 = 2.f * std::numbers::pi / 3.f;

            if (time == 0.f)
                return 0.f;
            else if (time == 1.f)
                return 1.f;
            else
                return -std::powf(2.f, 10.f * (time - 1.f)) * std::sinf((time * 10.f - 10.75f) * c4);
        }

        consteval float elastic_out(float time)
        {
            constexpr float tune = 2.f * std::numbers::pi / 3.f;
            if (time == 0.f)
                return 0.f;
            else if (time == 1.f)
                return 1.f;
            else
                return std::powf(2.f, -10.f * time) * std::sinf((time * 10.f - 0.75f) * tune) + 1.f;
        }

        consteval float elastic_in_out(float time)
        {
            constexpr float tune = 2.f * std::numbers::pi / 4.5f;
            if (time == 0.f)
                return 0.f;
            else if (time == 1.f)
                return 1.f;
            
            if (time < 0.5f)
                return -0.5f * std::powf(2.f, -20.f * time - 10.f) * std::sinf((20.f * time - 11.125f) * tune);
            else
                return 0.5f * std::powf(2.f, -20.f * time + 10.f) * std::sinf((20.f * time - 11.125f) * tune) + 1.f;
        }

        consteval float back_in(float time)
        {
            constexpr float c1 = 1.70158f;
            constexpr float c3 = c1 + 1.f;

            return c3 * time * time * time - c1 * time * time;
        }

        consteval float back_out(float time)
        {
            constexpr float c1 = 1.70158f;
            constexpr float c3 = c1 + 1.f;
            time -= 1.f;

            return 1.f + c3 * time * time * time + c1 * time * time;
        }

        consteval float back_in_out(float time)
        {
            constexpr float c1 = 1.70158f;
            constexpr float c2 = c1 * 1.525f;

            return time < 0.5
                ? (4.f * time * time * ((c2 + 1.f) * 2.f * time - c2)) / 2.f
                : (std::powf(2.f * time - 2.f, 2.f) * ((c2 + 1.f) * (time * 2.f - 2.f) + c2) + 2.f) / 2.f;
        }

        // tables
        constexpr auto lut_sine_in = make_lut(&sine_in);
        constexpr auto lut_sine_out = make_lut(&sine_out);
        constexpr auto lut_sine_in_out = make_lut(&sine_out);
        constexpr auto lut_quad_in = make_lut(&quad_in);
        constexpr auto lut_quad_out = make_lut(&quad_out);
        constexpr auto lut_quad_in_out = make_lut(&quad_in_out);
        constexpr auto lut_cubic_in = make_lut(&cubic_in);
        constexpr auto lut_cubic_out = make_lut(&cubic_out);
        constexpr auto lut_cubic_in_out = make_lut(&cubic_in_out);
        constexpr auto lut_bounce_in = make_lut(&bounce_in);
        constexpr auto lut_bounce_out = make_lut(&bounce_out);
        constexpr auto lut_bounce_in_out = make_lut(&bounce_in_out);
        constexpr auto lut_elastic_in = make_lut(&elastic_in);
        constexpr auto lut_elastic_out = make_lut(&elastic_out);
        constexpr auto lut_elastic_in_out = make_lut(&elastic_in_out);
        constexpr auto lut_back_in = make_lut(&back_in);
        constexpr auto lut_back_out = make_lut(&back_out);
        constexpr auto lut_back_in_out = make_lut(&back_in_out);
    }
}
#include <math/Graphics.tpp>