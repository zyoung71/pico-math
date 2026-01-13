#include <math/Vec2.h>

#include <cmath>

template<typename D>
Vec2<D> Vec2<D>::operator+(const Vec2<D>& other) const
{
    return {x+other.x, y+other.y};
}

template<typename D>
Vec2<D> Vec2<D>::operator-(const Vec2<D>& other) const
{
    return {x-other.x, y-other.y};
}

template<typename D>
Vec2<D> Vec2<D>::operator*(D scale) const
{
    return {x*scale, y*scale};
}

template<typename D>
Vec2<D> Vec2<D>::operator/(D scale) const
{
    return {x/scale, y/scale};
}

template<typename D>
Vec2<D>& Vec2<D>::operator+=(const Vec2<D>& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

template<typename D>
Vec2<D>& Vec2<D>::operator-=(const Vec2<D>& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

template<typename D>
Vec2<D>& Vec2<D>::operator*=(D scale)
{
    x *= scale;
    y *= scale;
    return *this;
}

template<typename D>
Vec2<D>& Vec2<D>::operator/=(D scale)
{
    x /= scale;
    y /= scale;
    return *this;
}

template<typename D>
float Vec2<D>::Length() const
{
    return std::sqrt(x*x+y*y);
}

template<typename D>
float Vec2<D>::Dot(const Vec2<D>& other) const
{
    return x*other.x + y*other.y;
}

template<typename D>
Vec2<D> Vec2<D>::Normalize() const
{
    float len = Length();
    return {x / len, y / len};
}