#ifndef ICURVE3D_H
#define ICURVE3D_H

#include "Point3D.h"

class ICurve3D
{
public:
    virtual Point3D GetPoint(double t) const = 0;
    virtual Point3D GetTangent(double t) const = 0;
    virtual void Print() const = 0;    
};

#endif // ICURVE3D_H