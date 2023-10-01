#include <stdexcept>
#include <cmath>
#include <string>
#include <iostream>
#include "Ellipse3D.h"


Ellipse3D::Ellipse3D(double radiusA, double radiusB)
{
    if (radiusA <= 0) {
        throw std::runtime_error(std::string("Invalid radius A"));
    } else if (radiusB <= 0) {
        throw std::runtime_error(std::string("Invalid radius B"));
    }
    this->radiusA = radiusA;
    this->radiusB = radiusB;
}

Point3D Ellipse3D::GetPoint(double t) const 
{
    return Point3D(radiusA * std::cos(t), radiusB * std::sin(t), 0);
}

Point3D Ellipse3D::GetTangent(double t) const
{
    return Point3D(-radiusA * std::sin(t), radiusB * std::cos(t), 0);
}

void Ellipse3D::Print() const
{
    std::cout << "ellipse radiusA = " << radiusA << ' ' << "radiusB = " << radiusB << std::endl;
}

