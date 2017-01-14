#include <iostream>
#include <gtest/gtest.h>
#include "util/point.hpp"
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include "pendulum.hpp"

class Test {
private:
    std::vector<int> testVector;

public:
    Test() {
        testVector.push_back(1);
        testVector.push_back(2);
        testVector.push_back(3);
        testVector.push_back(4);
        testVector.push_back(5);
    }

    std::vector<int>& getVector() {
        return testVector;
    }

    void printVector() {
        std::cout << "Printing Test vector...." << std::endl;
        for(int i : testVector) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }
};



int main(int argc, char **argv) {
/*
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
*/
    Pendulum p1 = Pendulum(1, 0, 2, Point());
    Pendulum p2 = Pendulum(2, 1, 3, p1);
    Pendulum p3 = Pendulum(3, -0.5, 4, p2);
    p1.attachChild(p2);
    p2.attachChild(p3);

    delete(&p1);

    Test testObj = Test();
    std::vector<int> &localVector = testObj.getVector();
    testObj.printVector();

    std::cout << "Printing local vector...." << std::endl;
    for(int i : localVector) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

    localVector.erase(localVector.begin());
    localVector.push_back(6);

    testObj.printVector();

    std::cout << "Printing local vector...." << std::endl;
    for(int i : localVector) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;

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