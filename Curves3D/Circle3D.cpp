#include <stdexcept>
#include <cmath>
#include <string>
#include <iostream>
#include "Circle3D.h"

Circle3D::Circle3D(double radius)
{
    if (radius <= 0) {
        throw std::runtime_error(std::string("Invalid radius"));
    }
    this->radius = radius;
}

Point3D Circle3D::GetPoint(double t) const 
{
    return Point3D(radius * std::cos(t), radius * std::sin(t), 0);
}

Point3D Circle3D::GetTangent(double t) const
{
    return Point3D(-radius * std::sin(t), radius * std::cos(t), 0);
}

void Circle3D::Print() const
{
    std::cout << "circle radius = " << radius << std::endl;
}

bool Circle3D::operator<(const Circle3D& other) const {
    return radius < other.radius;
}