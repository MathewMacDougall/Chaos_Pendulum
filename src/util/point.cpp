#include <cmath>
#include <float.h>
#include "point.hpp"
#include "../pendulum.hpp"

Point::Point() {
    xpos = 0.0;
    ypos = 0.0;
}

Point::Point(double x, double y) {
    xpos = x;
    ypos = y;
}

double Point::x() const {
    return this->xpos;
}

double Point::y() const {
    return this->ypos;
}

double Point::len() const {
    return sqrt(xpos*xpos + ypos*ypos);
}

double Point::lensq() const {
    return xpos*xpos + ypos*ypos;
}

void Point::move(double x, double y) {
    xpos += x;
    ypos += y;
}

void Point::set(double x, double y) {
    xpos = x;
    ypos = y;
}

void Point::rotate(double theta) {
    xpos = xpos * cos(theta) - ypos * sin(theta);
    ypos = xpos * sin(theta) + ypos * cos(theta);
}

Point Point::add(Point b) const {
    return Point(xpos + b.x(), ypos + b.y());
}

Point Point::sub(Point b) const {
    return Point(xpos - b.x(), ypos - b.y());
}

Point Point::norm() const {
    double length = len();
    return Point(xpos / length, ypos / length);
}

Point Point::clone() const {
    return Point(xpos, ypos);
}

bool Point::operator==(const Point &other) const {
    return fabs(xpos - other.x()) < DBL_EPSILON && fabs(ypos - other.y()) < DBL_EPSILON;
}

bool Point::operator!=(const Point &other) const {
    return !(*this == other);
}