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
    i ++;
    std::cout << "i = " << i << std::endl;
    std::cout << "intPtr = " << intPtr << std::endl;
    std::cout << "val of intPtr = " << *intPtr << std::endl;
    std::cout << "intRef = " << intRef << std::endl;

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