#include <iostream>
#include <fstream>
#include "pendulum.hpp"
#include "util/point.hpp"
#include "util/physics.hpp"
#include <cmath>

int main(int argc, char **argv) {

 double dt = 1.0 / 100.0;
    std::ofstream myFile ("position_output.txt");
    if(myFile.is_open()) {
        Pendulum p1 = Pendulum(5, 3*M_PI_4, 3, Point());
        Pendulum p2 = Pendulum(5, 4.1*M_PI_4, 3, p1);
        myFile << p1.getBobPosition().x() << ", " << p1.getBobPosition().y() << ", ";
        myFile << p2.getBobPosition().x() << ", " << p2.getBobPosition().y() << "\n";

        for(int i = 0; i < 1000; i++) {
            p1.update(dt);
            myFile << p1.getBobPosition().x() << ", " << p1.getBobPosition().y() << ", ";
            myFile << p2.getBobPosition().x() << ", " << p2.getBobPosition().y() << "\n";
        }

        myFile.close();
    } else {
        std::cout << "Could not open file" << std::endl;
    }
    std::cout << "DONE" << std::endl;
}
