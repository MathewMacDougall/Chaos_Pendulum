#include <iostream>
#include <gtest/gtest.h>
#include "util/point.hpp"
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include "pendulum.hpp"


int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

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