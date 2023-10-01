#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>

struct Point3D
{
    double x, y, z;
    explicit Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    void Print()
    {
        std::cout << "x = " << x << ' ' << "y = " << y << ' ' << "z = " << z << std::endl;
    }

};

#endif // POINT3D_H