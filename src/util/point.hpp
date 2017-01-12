#ifndef POINT_H
#define POINT_H

class Point final {

    private:
        double xpos;
        double ypos;

    public:
        // Creates a new Point object with coordinates (0, 0)
        Point();

        // Creates a new Point object with coordinates (x, y)
        Point(double, double);

        // Returns the x position of the Point
        double x() const;

        // Returns the y position of the Point
        double y() const;

        // Returns the length between the Point and (0, 0)
        double len() const;

        // Resurns the squared value of the length of the Point
        double lensq() const;

        // Translated the Point by (x, y)
        void move(double x, double y);

        // Changes the Point's coordinates to (x, y)
        void set(double x, double y);

        // Rotates the point by theta radians. Positive theta
        // rotates counterclockwise, negative theta rotates clockwise
        void rotate(double theta);

        // Adds b to the Point and returns a new Point
        Point add(Point b) const;

        // Subtracts b from the Point and returns a new Point
        Point sub(Point b) const;

        // Returns a new Point with len() = 1.0
        Point norm() const;

        // Creates and returns an identical Point object
        Point clone() const;

        // Returns true if and only if this is equal to other
        bool operator==(const Point& other) const;

        // Returns true if and only if this point is not equal to other
        bool operator!=(const Point& other) const;
};


#endif
