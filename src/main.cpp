#include <iostream>
#include <gtest/gtest.h>
#include "util/point.hpp"
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include "pendulum.hpp"


int main(int argc, char **argv) {

    int i = 10;
    int* intPtr = &i;
    int &intRef = i;

    intPtr += 2;
    intRef += 2;

























/*
    std::cout << "Chaos Pendulum Main exec\n" << std::endl;
    std::vector<Pendulum*> testVector;
    Pendulum p1 = Pendulum(1, 0, 3, Point());
    Pendulum p2 = Pendulum(2, M_PI_4, 2, p1);
    p1.attachChild(p2);

    testVector.push_back(&p2);
    //testVector.push_back(2);
    //testVector.push_back(5);
    //testVector.push_back(4);

    if((std::find(testVector.begin(), testVector.end(), &p2)) != testVector.end()) {
        std::cout << "int found";
    } else {
        std::cout << "int NOT found";
    }*/

}


/*
namespace std
{
    template <>
    struct hash<Point>
    {
        size_t operator()(const Point& p) const
        {
            return std::hash<double>()(p.x()) ^ std::hash<double>()(p.y());
        }
    };
};

namespace std
{
    template <>
    struct hash<Pendulum>
    {
        size_t operator()(const Pendulum& p) const noexcept
        {
            return (
                    (51 + std::hash<double>()(p.getMass())) * 51
                    + std::hash<double>()(p.getLength()) * 51
                    + std::hash<double>()(p.getParentPendulum()->getLength()) * 51
                    + std::hash<double>()(p.getParentPendulum()->getMass())
                    + std::hash<double>()(p.getBobPosition().x())
            );
        }
    };
}
*/