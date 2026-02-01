#include <math/Vec4.h>

#include <cmath>

template<typename D>
Vec4<D> Vec4<D>::operator+(const Vec4<D>& other) const
{
    return {x+other.x, y+other.y, z+other.z, w+other.w};
}

template<typename D>
Vec4<D> Vec4<D>::operator-(const Vec4<D>& other) const
{
    return {x-other.x, y-other.y, z-other.z, w-other.w};
}

template<typename D>
Vec4<D> Vec4<D>::operator*(D scale) const
{
    return {x*scale, y*scale, z*scale, w*scale};
}

template<typename D>
Vec4<D> Vec4<D>::operator/(D scale) const
{
    return {x/scale, y/scale, z/scale, w/scale};
}

template<typename D>
Vec4<D>& Vec4<D>::operator+=(const Vec4<D>& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

template<typename D>
Vec4<D>& Vec4<D>::operator-=(const Vec4<D>& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

template<typename D>
Vec4<D>& Vec4<D>::operator*=(D scale)
{
    x *= scale;
    y *= scale;
    z *= scale;
    w *= scale;
    return *this;
}

template<typename D>
Vec4<D>& Vec4<D>::operator/=(D scale)
{
    x /= scale;
    y /= scale;
    z /= scale;
    w /= scale;
    return *this;
}

template<typename D>
float Vec4<D>::Length() const
{
    return std::sqrt(x*x+y*y+z*z+w*w);
}

template<typename D>
float Vec4<D>::Dot(const Vec4<D>& other) const
{
    return x*other.x + y*other.y + z*other.z + w*other.w;
}

template<typename D>
Vec4<D> Vec4<D>::Normalize() const
{
    float len = Length();
    return {x / len, y / len, z / len, w / len};
}

template<typename D>
bool Vec4<D>::operator==(const Vec4& other) const 
{
    return x == other.x && y == other.y && z == other.z && w == other.w;
}

template<typename D>
bool Vec4<D>::operator!=(const Vec4& other) const 
{
    return x != other.x || y != other.y || z != other.z || w != other.w;
}

template<typename D>
bool Vec4<D>::operator<(const Vec4& other) const 
{
    return Length() < other.Length();
}

template<typename D>
bool Vec4<D>::operator>(const Vec4& other) const 
{
    return Length() > other.Length();
}

template<typename D>
bool Vec4<D>::operator<=(const Vec4& other) const 
{
    return Length() <= other.Length();
}

template<typename D>
bool Vec4<D>::operator>=(const Vec4& other) const 
{
    return Length() >= other.Length();
}

template<typename D>
Vec4<D> operator*(D scale, const Vec4<D>& vec)
{
    return vec * scale;
}

template<typename D>
Vec4<D> operator/(D scale, const Vec4<D>& vec)
{
    return Vec4<D>{scale / vec.x, scale / vec.y, scale / vec.z, scale / vec.z};
}

template<typename D>
size_t std::hash<Vec4<D>>::operator()(const Vec4<D>& key) const
{
    return (((std::hash<D>()(key.x) ^ (std::hash<D>()(key.y) << 1)) >> 1) ^ (std::hash<D>()(key.z) << 1)) ^ (std::hash<D>()(key.w) << 2);
}