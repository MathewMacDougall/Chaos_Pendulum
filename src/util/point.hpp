#ifndef POINT_H
#define POINT_H

class Point {

    public:
        // Creates a new Point object with coordinates (0, 0)
        Point();

        // Creates a new Point object with coordinates (x, y)
        Point(double x, double y);

        // Creates a new Point using polar coordinates
        // must have -180 < theta <= 180
        // theta = 0 represents "down"
        //Point(int theta, double length);

        // Returns the x position of the Point
        double x();

        // Returns the y position of the Point
        double y();

        // Returns the length between the Point and (0, 0)
        double len();

        // Resurns the squared value of the length of the Point
        double lensq();

        // Translated the Point by (x, y)
        void move(double x, double y);

        // Changes the Point's coordinates to (x, y)
        void set(double x, double y);

        // Adds b to the Point and returns a new Point
        Point add(Point b);

        // Subtracts b from the Point and returns a new Point
        Point sub(Point b);

        // Returns a new Point with len() = 1.0
        Point mod();

        // Creates and returns an identical Point object
        Point clone();

};


#endif
