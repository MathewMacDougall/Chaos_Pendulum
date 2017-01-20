#include <iostream>
#include <fstream>
#include "pendulum.hpp"
#include "util/point.hpp"
#include "util/physics.hpp"
#include <cmath>

int main(int argc, char **argv) {

 double dt = 1.0 / 60.0;
    std::ofstream myFile ("position_output.txt");
    if(myFile.is_open()) {
        Pendulum p1 = Pendulum(5, 1, 3, Point());
        myFile << p1.getBobPosition().x() << ", " << p1.getBobPosition().y() << "\n";

        for(int i = 0; i < 500; i++) {
            p1.update(dt);
            myFile << p1.getBobPosition().x() << ", " << p1.getBobPosition().y() << "\n";
            std::cout << "printing to file" << std::endl;
        }

        myFile.close();
    } else {
        std::cout << "Could not open file" << std::endl;
    }
    std::cout << "TEST" << std::endl;
}
