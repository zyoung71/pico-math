#include <math/Quat.h>

#include <cmath>

template<typename D>
float Quat<D>::Magnitude() const
{
    return std::sqrt(w*w+x*x+y*y+z*z);
}

template<typename D>
Quat<D> Quat<D>::Normalize() const
{
    float mag = Magnitude();
    return {
        w / mag,
        x / mag,
        y / mag,
        z / mag
    };
}

template<typename D>
Quat<D> Quat<D>::Inverse() const
{
    D mag = Magnitude();
    return Conjugate() * ((D)1.0 / (mag*mag));
}

template<typename D>
Quat<D> Quat<D>::operator*(const Quat<D>& q) const
{
    return Quat<D>(
        w*q.w - x*q.x - y*q.y - z*q.z,  // new w
        w*q.x + x*q.w + y*q.z - z*q.y,  // new x
        w*q.y - x*q.z + y*q.w + z*q.x,  // new y
        w*q.z + x*q.y - y*q.x + z*q.w   // new z
    );
}

template<typename D>
Quat<D> Quat<D>::operator*(D k) const
{
    return {w*k, x*k, y*k, z*k};
}

template<typename D>
Quat<D>& Quat<D>::operator*=(const Quat<D>& q)
{
    *this = *this * q;
    return *this;
}

template<typename D>
Quat<D>& Quat<D>::operator*=(D k)
{
    *this = *this * k;
    return *this;
}

template<typename D>
Quat<D> Quat<D>::operator/(const Quat<D>& other) const
{
    *this = *this * other.Inverse();
    return *this;
}

template<typename D>
Quat<D> Quat<D>::operator/(D k) const
{
    return {w/k, x/k, y/k, z/k};
}

template<typename D>
Quat<D>& Quat<D>::operator/=(const Quat<D>& q)
{
    *this = *this / q;
    return *this;
}

template<typename D>
Quat<D>& Quat<D>::operator/=(D k)
{
    *this = *this / k;
    return *this;
}

template<typename D>
Quat<D> Quat<D>::Conjugate() const
{
    return {w, -x, -y, -z};
}

template<typename D>
Quat<D> Quat<D>::operator-() const
{
    return {-w, -x, -y, -z};
}

template<typename D>
Quat<D> Quat<D>::operator++(int)
{
    Quat<D> before = *this;
    w++;
    x++;
    y++;
    z++;
    return before;
}

template<typename D>
Quat<D> Quat<D>::operator--(int)
{
    Quat<D> before = *this;
    w--;
    x--;
    y--;
    z--;
    return before;
}

template<typename D>
Quat<D>& Quat<D>::operator++()
{
    ++w;
    ++x;
    ++y;
    ++z;
    return *this;
}

template<typename D>
Quat<D>& Quat<D>::operator--()
{
    --w;
    --x;
    --y;
    --z;
    return *this;
}

template<typename D>
bool Quat<D>::operator==(const Quat<D>& other) const
{
    return (w == other.w && x == other.x && y == other.y && z == other.z);
}

template<typename D>
bool Quat<D>::operator!=(const Quat<D>& other) const
{
    return !(*this == other);
}