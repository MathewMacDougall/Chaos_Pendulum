#ifndef POINT_H
#define POINT_H

#include <cmath>

class Point final {

    private:
        double xpos;
        double ypos;

    public:
        /**
         * Constructs a new Point object with coordinates (0, 0)
         */
        Point();

        /**
         * Constructs a new Point object with coordinates (x, y)
         *
         * @param x -  the x-coordinate of the Point
         * @param y - the y-coordinate of the Point
         */
        Point(double, double);

        /**
         * Returns the x coordinate of the Point
         *
         * @return the x coordinate of the Point
         */
        double x() const;

        /**
         * Returns the y coordinate of the Point
         *
         * @return the y coordinate of the Point
         */
        double y() const;

        /** Returns the length of the vector between this Point and (0, 0)
         *
         * @return the length of the vector between this Point and (0, 0)
         */
        double len() const;

        /**
         * Returns the squared length of the vector bewteen this Point and (0, 0)
         *
         * @return the sqaured length of the vector between this Point and (0, 0)
         */
        double lensq() const;

        /**
         * Returns the angle (in radians) of the vector represented by this Point
         * The angle is relative to the positive x-axis on the x-y plane
         *
         * @return the angle in radians of this Point 0 <= angle < 2*PI
         */
        double angle() const;

        /**
         * Translates the coordinate of this Point by (x, y)
         *
         * @param x - the x coordinate to translate by
         * @param y  - the y coordinate to translate by
         */
        void move(double x, double y);

        /**
         * Sets this Point's coordinates to (x, y)
         *
         * @param x - the new x coordinate of the Point
         * @param y - the new y coordinate of the Point
         */
        void set(double x, double y);

        /**
         * Rotates this Point by theta radians around the origin.
         * Positive theta values rotate counter-clockwise, negative theta values
         * rotate clockwise
         *
         * @param theta - the radians to rotate the Point by. Positive values rotate counter-clockwise,
         *                negative values rotate clockwise
         */
        void rotate(double theta);

        /**
         * Returns a new Point representing this Point plus Point b
         *
         * @param b - the Point to add to this Point
         * @return a new Point with the value of this Point added to b
         */
        Point add(Point b) const;

        /**
        * Returns a new Point representing This Point minus Point b
        *
        * @param b - the Point to subtract from this Point
        * @return a new Point with the value of b subtracted from this Point
        */
        Point sub(Point b) const;

        /**
         * Returns a new Point representing the unit vector of this Point
         *
         * @return a new Point representing the unit vector of this Point
         */
        Point norm() const;

        /**
         * Returns a point representing the projection of this Point onto other
         *
         * @param other - the Point to project on to
         * @return the projection of this onto other
         */
        Point projectOnto(const Point other);

        /**
         * Computes the dot product of this Point and other
         *
         * @param other - the other point in the dot product
         * @return the dot product of this and other
         */
        double dot(const Point other);

        /**
         * Returns a new Point representing the vector perpendicular to this Point
         *
         * @return a new Point representing the vector perpendicular to this Point.
         *         this perpendicular vector is always facing in the direction of this Point rotated counter-clockwise
         */
        Point perp() const;

        /**
         * Returns a copy of this Point
         *
         * @return a new Point with the same values (x, y) as this Point
         */
        Point clone() const;

        /**
         * Returns true if this Point points in the same direction as other, withing a threshold
         *
         * @param other - the other point to compare direction to
         * @param angleThreshold - the angle threshold (in radians)
         * @return true if this Point's angle is within angleTolerance of other
         */
        bool isSameDirectionAs(Point other, double angleThreshold = M_PI / 100);

        /**
         * Overrides the == operator. Returns true if and only if this Point has the same
         * x and y coordinates of other
         *
         * @param other - the point to compare with for equality
         * @return true if this Point has the same x and y coordinates as other, and false otherwise
         */
        bool operator==(const Point& other) const;

        /**
        * Overrides the != operator. Returns true if and only if at least one of this Point's x or y coordinates
        * does not equal the x or y coordinate of other
        *
        * @param other - the point to compare with for equality
        * @return true if this Point has at least 1 different x or y coordinate compared to other, false otherwise
         */
        bool operator!=(const Point& other) const;

        /**
         * Overrides the * operator. Returns the scalar product of this Point and scale
         *
         * @param scale - the value to scale this point by
         * @return the scalar product of this point and scale
         */
        Point operator*(const double& scale) const;
};


#endif
