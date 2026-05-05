#include <math/Vec2.h>

#include <cmath>

template<typename D>
constexpr Vec2<D> Vec2<D>::operator+(const Vec2<D>& other) const
{
    return {x+other.x, y+other.y};
}

template<typename D>
constexpr Vec2<D> Vec2<D>::operator-(const Vec2<D>& other) const
{
    return {x-other.x, y-other.y};
}

template<typename D>
constexpr Vec2<D> Vec2<D>::operator*(const Vec2<D>& other) const
{
    return {x*other.x, y*other.y};
}

template<typename D>
constexpr Vec2<D> Vec2<D>::operator/(const Vec2<D>& other) const
{
    return {x/other.x, y/other.y};
}

template<typename D>
constexpr Vec2<D> Vec2<D>::operator*(D scale) const
{
    return {x*scale, y*scale};
}

template<typename D>
constexpr Vec2<D> Vec2<D>::operator/(D scale) const
{
    return {x/scale, y/scale};
}

template<typename D>
constexpr Vec2<D>& Vec2<D>::operator+=(const Vec2<D>& other)
{
    x += other.x;
    y += other.y;
    return *this;
}

template<typename D>
constexpr Vec2<D>& Vec2<D>::operator-=(const Vec2<D>& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}

template<typename D>
constexpr Vec2<D>& Vec2<D>::operator*=(const Vec2<D>& other)
{
    x *= other.x;
    y *= other.y;
    return *this;
}

template<typename D>
constexpr Vec2<D>& Vec2<D>::operator/=(const Vec2<D>& other)
{
    x /= other.x;
    y /= other.y;
    return *this;
}

template<typename D>
constexpr Vec2<D>& Vec2<D>::operator*=(D scale)
{
    x *= scale;
    y *= scale;
    return *this;
}

template<typename D>
constexpr Vec2<D>& Vec2<D>::operator/=(D scale)
{
    x /= scale;
    y /= scale;
    return *this;
}

template<typename D>
constexpr Vec2<D>::FloatType Vec2<D>::Length() const
{
    return std::sqrt(x*x+y*y);
}

template<typename D>
constexpr Vec2<D>::FloatType Vec2<D>::Dot(const Vec2<D>& other) const
{
    return x*other.x + y*other.y;
}

template<typename D>
constexpr Vec2<D>& Vec2<D>::Normalize()
{
    float len = Length();
    x /= len;
    y /= len;
    return *this;
}

template<typename D>
constexpr Vec2<D>& Vec2<D>::Round()
{
    x = std::round(x);
    y = std::round(y);
    return *this;
}

template<typename D>
constexpr Vec2<D>& Vec2<D>::Floor()
{
    x = std::floor(x);
    y = std::floor(y);
    return *this;
}

template<typename D>
constexpr Vec2<D>& Vec2<D>::Ceil()
{
    x = std::ceil(x);
    y = std::ceil(y);
    return *this;
}

template<typename D>
constexpr D Vec2<D>::Min() const
{
    return std::min(x, y);
}

template<typename D>
constexpr D Vec2<D>::Max() const
{
    return std::max(x, y);
}

template<typename D>
constexpr bool Vec2<D>::operator==(const Vec2& other) const 
{
    return x == other.x && y == other.y;
}

template<typename D>
constexpr bool Vec2<D>::operator!=(const Vec2& other) const 
{
    return x != other.x || y != other.y;
}

template<typename D>
constexpr bool Vec2<D>::operator<(const Vec2& other) const 
{
    return Length() < other.Length();
}

template<typename D>
constexpr bool Vec2<D>::operator>(const Vec2& other) const 
{
    return Length() > other.Length();
}

template<typename D>
constexpr bool Vec2<D>::operator<=(const Vec2& other) const 
{
    return Length() <= other.Length();
}

template<typename D>
constexpr bool Vec2<D>::operator>=(const Vec2& other) const 
{
    return Length() >= other.Length();
}

template<typename D>
constexpr Vec2<D> operator*(D scale, const Vec2<D>& vec)
{
    return vec * scale;
}

template<typename D>
constexpr Vec2<D> operator/(D scale, const Vec2<D>& vec)
{
    return Vec2<D>{scale / vec.x, scale / vec.y};
}

template<typename D>
constexpr size_t std::hash<Vec2<D>>::operator()(const Vec2<D>& key) const
{
    return std::hash<D>()(key.x) ^ (std::hash<D>()(key.y) << 1);
}

template<typename D>
constexpr Vec2<D> Vec2<D>::Normalize(const Vec2<D>& v)
{
    float len = v.Length();
    return Vec2<D>{v.x / len, v.y / len};
}

template<typename D>
constexpr Vec2<D> Vec2<D>::Round(const Vec2<D>& v)
{
    return Vec2<D>{std::round(v.x), std::round(v.y)};
}

template<typename D>
constexpr Vec2<D> Vec2<D>::Floor(const Vec2<D>& v)
{
    return Vec2<D>{std::floor(v.x), std::floor(v.y)};
}

template<typename D>
constexpr Vec2<D> Vec2<D>::Ceil(const Vec2<D>& v)
{
    return Vec2<D>{std::ceil(v.x), std::ceil(v.y)};
}