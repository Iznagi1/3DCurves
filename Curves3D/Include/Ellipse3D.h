#ifndef ELLIPSE3D_H
#define ELLIPSE3D_H

#include <stdexcept>
#include "ICurve3D.h"

class Ellipse3D : public ICurve3D
{
    double radiusA;
    double radiusB;
public:
    explicit Ellipse3D(double radiusA, double radiusB);

    double GetRadiusA() const { return radiusA; }
    double GetRadiusB() const { return radiusB; }
    void SetRadiusA(double radiusA) { this->radiusA = radiusA; }
    void SetRadiusB(double radiusB) { this->radiusB = radiusB; }

    Point3D GetPoint(double t) const override;
    Point3D GetTangent(double t) const override;
    void Print() const override;

};

#endif // ELLIPSE3D_H