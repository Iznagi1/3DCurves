#ifndef CIRCLE3D_H
#define CIRCLE3D_H

#include <stdexcept>
#include "ICurve3D.h"

class Circle3D : public ICurve3D
{
protected:
    double radius;
public:
    explicit Circle3D(double radius);

    double GetRadius() const { return radius; }
    void SetRadius(double radius) { this->radius = radius; }
    bool operator<(const Circle3D& other) const;

    Point3D GetPoint(double t) const override;
    Point3D GetTangent(double t) const override;
    void Print() const override;
};

#endif // CIRCLE3D_H