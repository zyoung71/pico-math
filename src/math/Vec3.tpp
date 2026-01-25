#include <math/Vec3.h>

#include <cmath>

template<typename D>
Vec3<D> Vec3<D>::operator+(const Vec3<D>& other) const
{
    return {x+other.x, y+other.y, z+other.z};
}

template<typename D>
Vec3<D> Vec3<D>::operator-(const Vec3<D>& other) const
{
    return {x-other.x, y-other.y, z-other.z};
}

template<typename D>
Vec3<D> Vec3<D>::operator*(D scale) const
{
    return {x*scale, y*scale, z*scale};
}

template<typename D>
Vec3<D> Vec3<D>::operator/(D scale) const
{
    return {x/scale, y/scale, z/scale};
}

template<typename D>
Vec3<D>& Vec3<D>::operator+=(const Vec3<D>& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

template<typename D>
Vec3<D>& Vec3<D>::operator-=(const Vec3<D>& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

template<typename D>
Vec3<D>& Vec3<D>::operator*=(D scale)
{
    x *= scale;
    y *= scale;
    z *= scale;
    return *this;
}

template<typename D>
Vec3<D>& Vec3<D>::operator/=(D scale)
{
    x /= scale;
    y /= scale;
    z /= scale;
    return *this;
}

template<typename D>
float Vec3<D>::Length() const
{
    return std::sqrt(x*x+y*y+z*z);
}

template<typename D>
float Vec3<D>::Dot(const Vec3<D>& other) const
{
    return x*other.x + y*other.y + z*other.z;
}

template<typename D>
Vec3<D> Vec3<D>::Normalize() const
{
    float len = Length();
    return {x / len, y / len, z / len};
}

template<typename D>
Vec3<D> Vec3<D>::Cross(const Vec3<D>& other) const
{
    return Vec3<D>{y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x};
}

template<typename D>
bool Vec3<D>::operator==(const Vec3& other) const 
{
    return x == other.x && y == other.y && z == other.z;
}

template<typename D>
bool Vec3<D>::operator!=(const Vec3& other) const 
{
    return x != other.x || y != other.y || z != other.z;
}

template<typename D>
bool Vec3<D>::operator<(const Vec3& other) const 
{
    return Length() < other.Length();
}

template<typename D>
bool Vec3<D>::operator>(const Vec3& other) const 
{
    return Length() > other.Length();
}

template<typename D>
bool Vec3<D>::operator<=(const Vec3& other) const 
{
    return Length() <= other.Length();
}

template<typename D>
bool Vec3<D>::operator>=(const Vec3& other) const 
{
    return Length() >= other.Length();
}

template<typename D>
Vec3<D> operator*(D scale, const Vec3<D>& vec)
{
    return vec * scale;
}

template<typename D>
Vec3<D> operator/(D scale, const Vec3<D>& vec)
{
    return Vec3<D>{scale / vec.x, scale / vec.y, scale / vec.z};
}