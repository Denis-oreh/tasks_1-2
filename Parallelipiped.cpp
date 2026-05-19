#include "Parallelipiped.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>

static const double EPS = std::numeric_limits<double>::epsilon() * 1e7;

void Parallelipiped::updateDimensions() {
    length = std::abs(p2.getX() - p1.getX());
    width = std::abs(p2.getY() - p1.getY());
    height = std::abs(p2.getZ() - p1.getZ());

    if (length <= EPS || width <= EPS || height <= EPS) {
        throw std::invalid_argument("¬се размеры должны быть положительными числами");
    }
}

Parallelipiped::Parallelipiped()
    : p1(0, 0, 0), p2(1, 1, 1), length(1), width(1), height(1) {
}

Parallelipiped::Parallelipiped(const Point& v1, const Point& v2, const Point& v3, const Point& v4) {

    double dx = v2.getX() - v1.getX();
    double dy = v3.getY() - v1.getY();
    double dz = v4.getZ() - v1.getZ();

    length = std::abs(dx);
    width = std::abs(dy);
    height = std::abs(dz);

    if (length <= EPS || width <= EPS || height <= EPS) {
        throw std::invalid_argument("¬се размеры должны быть положительными числами");
    }

    double minX = v1.getX();
    double minY = v1.getY();
    double minZ = v1.getZ();
    double maxX = minX + dx;
    double maxY = minY + dy;
    double maxZ = minZ + dz;

    p1 = Point(std::min(minX, maxX), std::min(minY, maxY), std::min(minZ, maxZ));
    p2 = Point(std::max(minX, maxX), std::max(minY, maxY), std::max(minZ, maxZ));
}

Parallelipiped::Parallelipiped(const Point& vertex, double l, double w, double h) {
    if (l <= EPS || w <= EPS || h <= EPS) {
        throw std::invalid_argument("ƒлина, ширина и высота должны быть положительными числами");
    }
    length = l;
    width = w;
    height = h;
    p1 = vertex;
    p2 = Point(vertex.getX() + length, vertex.getY() + width, vertex.getZ() + height);
}

Parallelipiped::Parallelipiped(const Point& minVertex, const Point& maxVertex) {
    if (minVertex.getX() > maxVertex.getX() ||
        minVertex.getY() > maxVertex.getY() ||
        minVertex.getZ() > maxVertex.getZ()) {
        throw std::invalid_argument("ѕерва€ вершина должна быть минимальной, втора€ - максимальной");
    }
    p1 = minVertex;
    p2 = maxVertex;
    updateDimensions();
}

Parallelipiped::Parallelipiped(double x1, double y1, double z1,
    double x2, double y2, double z2,
    double x3, double y3, double z3,
    double x4, double y4, double z4)
    : Parallelipiped(Point(x1, y1, z1), Point(x2, y2, z2),
        Point(x3, y3, z3), Point(x4, y4, z4)) {
}

double Parallelipiped::getSurfaceArea() const {
    return 2.0 * (length * width + length * height + width * height);
}

double Parallelipiped::getVolume() const {
    return length * width * height;
}

std::string Parallelipiped::toString() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << "ѕараллелепипед [длина=" << length
        << ", ширина=" << width
        << ", высота=" << height
        << ", объЄм=" << getVolume()
        << ", площадь поверхности=" << getSurfaceArea()
        << "]; ¬ершины: " << p1 << " - " << p2;
    return ss.str();
}

void Parallelipiped::read(std::istream& is) {
    int choice;
    std::cout << "¬ыберите способ создани€:\n"
        << "1 - по трЄм вершинам (обща€ вершина + смежные по X, Y, Z)\n"
        << "2 - по вершине и размерам (длина ширина высота)\n"
        << "3 - по двум вершинам главной диагонали (минимальна€ и максимальна€)\n"
        << "4 - по 12 координатам (x1 y1 z1 x2 y2 z2 x3 y3 z3 x4 y4 z4)\n";
    is >> choice;

    switch (choice) {
    case 1: {
        Point v1, v2, v3, v4;
        std::cout << "¬ведите 4 вершины (x y z дл€ каждой):\n";
        is >> v1 >> v2 >> v3 >> v4;
        *this = Parallelipiped(v1, v2, v3, v4);
        break;
    }
    case 2: {
        Point vertex;
        double l, w, h;
        std::cout << "¬ведите вершину (x y z), затем длину, ширину, высоту:\n";
        is >> vertex >> l >> w >> h;
        *this = Parallelipiped(vertex, l, w, h);
        break;
    }
    case 3: {
        Point minV, maxV;
        std::cout << "¬ведите минимальную вершину (x y z) и максимальную вершину (x y z):\n";
        is >> minV >> maxV;
        *this = Parallelipiped(minV, maxV);
        break;
    }
    case 4: {
        double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
        std::cout << "¬ведите 12 координат (x1 y1 z1 x2 y2 z2 x3 y3 z3 x4 y4 z4):\n";
        is >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;
        *this = Parallelipiped(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4);
        break;
    }
    default:
        throw std::invalid_argument("Ќеверный способ создани€");
    }
}

Parallelipiped Parallelipiped::readFrom(std::istream& is) {
    Parallelipiped p;
    p.read(is);
    return p;
}