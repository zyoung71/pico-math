#include <math/AABB.h>

template<typename D>
bool AABB<D>::Intersects(const AABB<D>& other) const
{
    return (xmin < other.xmax && xmax > other.xmin && ymin < other.ymax && ymax > other.ymin);
}