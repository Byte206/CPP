#include "Point.hpp"

static int get_z(Point const a, Point const b, Point const p) {
    Fixed z = (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());
    
    if (z > 0)
        return 1;
    if (z < 0)
        return -1;
    return 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    int z[3];

    z[0] = get_z(a, b, point);
    z[1] = get_z(b, c, point);
    z[2] = get_z(c, a, point);

    if (z[0] == 0 || z[1] == 0 || z[2] == 0)
        return false;
    
    if ((z[0] > 0 && z[1] > 0 && z[2] > 0) || (z[0] < 0 && z[1] < 0 && z[2] < 0))
        return true;
    
    return false;
}
