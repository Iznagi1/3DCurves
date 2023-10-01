#ifndef HELIX3D_H
#define HELIX3D_H

#include <stdexcept>
#include "Circle3D.h"

class Helix3D : public Circle3D
{
    double step;
public:
    explicit Helix3D(double radius, double step);

    double GetStep() const { return step; }
    void SetStep(double step) { this->step = step; }

    Point3D GetPoint(double t) const override;
    Point3D GetTangent(double t) const override;
    void Print() const override;

};

#endif // HELIX3D_H