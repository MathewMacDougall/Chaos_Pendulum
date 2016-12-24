#include <cmath>


class Point {
    private:
        double xpos, ypos;

    public:

        Point() {
            xpos = 0.0;
            ypos = 0.0;
        }


        Point(double x, double y) {
            xpos = x;
            ypos = y;
        }


        /*
        Point (int theta, double length) {
            xpos = length * sin(theta);
            ypos = length;
        }*/


        double x() {
            return xpos;
        }

        double y() {
            return ypos;
        }

        double len() {
            return sqrt(xpos*xpos + ypos*ypos);
        }

        double lensq() {
            return xpos*xpos + ypos*ypos;
        }

        void move(double x, double y) {
            xpos += x;
            ypos += y;
        }

        void set(double x, double y) {
            xpos = x;
            ypos = y;
        }

        Point add(Point b) {
            return Point(xpos + b.x(), ypos + b.y());
        }

        Point sub(Point b) {
            return Point (xpos - b.x(), ypos - b.y());
        }

        Point mod() {
            double length = len();
            return Point(xpos / length, ypos / length);
        }

        Point clone() {
            return Point(xpos, ypos);
        }
};
