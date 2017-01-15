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

double Point::angle() const {
    if(xpos == 0) {
        if (ypos == 0) {
            return 0;
        } else {
            return ypos > 0 ? M_PI_2 : 3 * M_PI_4;
        }
    } else {
        return atan(ypos / xpos);
    }
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
    double xtemp = xpos;
    xpos = xpos * std::cos(theta) - ypos * std::sin(theta);
    ypos = xtemp * std::sin(theta) + ypos * std::cos(theta);
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

Point Point::projectOnto(const Point other) {
    double scalar = this->dot(other) / other.lensq();
    return other * scalar;
}

double Point::dot(const Point other) {
    return xpos * other.x() + ypos * other.y();
}

Point Point::perp() const {
    return Point(-ypos, xpos);
}

Point Point::clone() const {
    return Point(xpos, ypos);
}

bool Point::operator==(const Point &other) const {
    return fabs(xpos - other.x()) < 10 * DBL_EPSILON && fabs(ypos - other.y()) < 10 * DBL_EPSILON;
}

bool Point::operator!=(const Point &other) const {
    return !(*this == other);
}

Point Point::operator*(const double &scale) const {
    return Point(xpos * scale, ypos * scale);
}