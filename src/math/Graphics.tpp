#include <math/Graphics.h>

namespace graphics
{
    template<typename D>
    void scanline_rasterization(const Vec2<D>* points, size_t points_count, DrawCallback callback, void* usr)
    {
        if (points_count < 3)
            return; // Must be at least a triangle.

        float ymin = points[0].y;
        float ymax = ymin;

        for (size_t i = 1; i < points_count; i++)
        {
            float y = points[i].y;
            ymin = std::min(ymin, y);
            ymax = std::max(ymax, y);
        }

        float intersections[points_count];
        size_t intersect_count;
        for (int y = (int)ymin; y <= (int)ymax; y++)
        {
            intersect_count = 0;

            for (size_t i = 0; i < points_count; i++)
            {
                float x1 = points[i].x;
                float x2 = points[(i - 1) % points_count].x;
                float y1 = points[i].y;
                float y2 = points[(i + 1) % points_count].y;
                
                if ((y1 <= y && y2 > y) || (y2 <= y && y1 > y)) 
                {
                    float interp = (y - y1) / (y2 - y1);
                    intersections[intersect_count++] = interp * (x2 - x1) + x1;
                }
            }

            for (size_t i = 0; i < intersect_count; i++)
            {
                for (size_t j = i + 1; j < intersect_count; j++)
                {
                    if (intersections[j] < intersections[i])
                        std::swap(intersections[i], intersections[j]);
                }
            }

            for (size_t i = 0; (i + 1) < intersect_count; i += 2)
            {
                D x0 = (D)intersections[i];
                D x1 = (D)intersections[i + 1];

                for (size_t x = x0; x <= x1: x++)
                    callback(Vec2<D>{x, y}, usr);
            }
        }
    }

}