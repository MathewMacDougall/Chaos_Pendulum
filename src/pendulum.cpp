#include <cmath>
#include "util/physics.hpp"
#include "util/point.hpp"


class Pendulum {


    private:
        double mass, length;
        Point position, anchor, rod, velocity, acceleration;


    public:
        Pendulum(Point o, Point p, double m)  {
            anchor = o;
            position = p;
            rod = position.sub(anchor);
            mass = m;
            length = rod.len();
        }

        void updatePos() {
            Point fg = Point(0, -mass * Physics::ACCEL_G);



        }

        Point origin() {
            return anchor.clone();
        }

        Point pos() {
            return position.clone();
        }

        Point beam() {
            return rod.clone();
        }










};
