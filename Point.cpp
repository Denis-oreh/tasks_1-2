#include "Point.h"
#include <iomanip>

const double Point::EPS = std::numeric_limits<double>::epsilon() * 1e7;

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

double Point::distanceTo(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    double dz = z - other.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

bool Point::operator==(const Point& other) const {
    return std::abs(x - other.x) <= EPS &&
        std::abs(y - other.y) <= EPS &&
        std::abs(z - other.z) <= EPS;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y >> p.z;
    return is;
}