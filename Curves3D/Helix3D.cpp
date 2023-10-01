#include <stdexcept>
#include <cmath>
#include <string>
#include <iostream>
#include "Helix3D.h"


Helix3D::Helix3D(double radius, double step) : Circle3D(radius)
{
    if (step == 0) {
        throw std::runtime_error(std::string("Invalid step"));
    }
    this->step = step;
}

Point3D Helix3D::GetPoint(double t) const 
{
    Point3D point = Circle3D::GetPoint(t);
    point.z = step * t / (2 * M_PI);
    return point;
}

Point3D Helix3D::GetTangent(double t) const
{
    Point3D tangent = Circle3D::GetTangent(t);
    tangent.z = step / (2 * M_PI);
    return tangent;
}

void Helix3D::Print() const
{
    std::cout << "helix radius = " << radius << ' ' << "step = " << step << std::endl;
}
