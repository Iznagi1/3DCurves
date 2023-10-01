#include <iostream>
#include <random>
#include <memory>
#include <algorithm>
#include "Circle3D.h"
#include "Ellipse3D.h"
#include "Helix3D.h"
#include <omp.h>

enum class Curves3D { Circle, Ellipse, Helix };

bool compareCircles(std::shared_ptr<ICurve3D> a, std::shared_ptr<ICurve3D> b) {
    return *(std::dynamic_pointer_cast<Circle3D>(a)) < *(std::dynamic_pointer_cast<Circle3D>(b));
}

static std::shared_ptr<ICurve3D> GetRandomCurve(std::mt19937& gen,
                                                 std::uniform_int_distribution<>& rangeOfTypes, 
                                                 std::uniform_int_distribution<>& rangeOfValues)
{
    int randomObject = rangeOfTypes(gen);
    Curves3D randomCurveType = static_cast<Curves3D>(randomObject);

    switch (randomCurveType) {
        case Curves3D::Circle:
            return std::make_shared<Circle3D>(rangeOfValues(gen));
        case Curves3D::Ellipse:
            return std::make_shared<Ellipse3D>(rangeOfValues(gen), rangeOfValues(gen));
        case Curves3D::Helix:
            return std::make_shared<Helix3D>(rangeOfValues(gen), rangeOfValues(gen));
    }
    return nullptr;
}

static void GetRandomCurves(std::vector<std::shared_ptr<ICurve3D>>& vectorOfCurves)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> rangeOfValues(1, 100);
    std::uniform_int_distribution<> rangeOfTypes(0, static_cast<int>(Curves3D::Helix));
    for (int i = 0; i < vectorOfCurves.size(); ++i) {
        vectorOfCurves[i] = std::move(GetRandomCurve(gen, rangeOfTypes, rangeOfValues));
    }
}

int main() {
    try {
        const int countOfCurves = 10;
        std::vector<std::shared_ptr<ICurve3D>> vectorOfCurves(countOfCurves);
        GetRandomCurves(vectorOfCurves);
        for (const auto& curve : vectorOfCurves) {
            curve->Print();
            curve->GetPoint(M_PI / 4).Print();
            curve->GetTangent(M_PI / 4).Print();
        }
    
        std::vector<std::shared_ptr<Circle3D>> vectorOfCircles;
        for (const auto& curve : vectorOfCurves) {
            if (std::dynamic_pointer_cast<Circle3D>(curve) && !std::dynamic_pointer_cast<Helix3D>(curve)) {
                vectorOfCircles.push_back(std::dynamic_pointer_cast<Circle3D>(curve));
            }
        }

        std::cout << "--------------------------------------\n";

        sort(vectorOfCircles.begin(), vectorOfCircles.end(), compareCircles);

        for (const auto& circle : vectorOfCircles) {
            circle->Print();
        }
        
        double totalSumOfRadii = 0;
        #pragma omp parallel for reduction(+:totalSumOfRadii)
        for (const auto& circle : vectorOfCircles) {
            totalSumOfRadii += circle->GetRadius();
        }

        std::cout << "Total sum of radii : " << totalSumOfRadii << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return 1;
    }
}