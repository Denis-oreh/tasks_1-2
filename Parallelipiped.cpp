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
        throw std::invalid_argument("Âñå ðàçìåðû äîëæíû áûòü ïîëîæèòåëüíûìè ÷èñëàìè");
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
        throw std::invalid_argument("Âñå ðàçìåðû äîëæíû áûòü ïîëîæèòåëüíûìè ÷èñëàìè");
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
        throw std::invalid_argument("Äëèíà, øèðèíà è âûñîòà äîëæíû áûòü ïîëîæèòåëüíûìè ÷èñëàìè");
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
        throw std::invalid_argument("Ïåðâàÿ âåðøèíà äîëæíà áûòü ìèíèìàëüíîé, âòîðàÿ - ìàêñèìàëüíîé");
    }
    p1 = minVertex;
    p2 = maxVertex;
    updateDimensions();
}

Parallelipiped::Parallelipiped(const double x1, const double y1, const double z1,
    const double x2, const double y2, const double z2,
    const double x3, const double y3, const double z3,
    const double x4, const double y4, const double z4)
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
    ss << "Ïàðàëëåëåïèïåä [äëèíà=" << length
        << ", øèðèíà=" << width
        << ", âûñîòà=" << height
        << ", îáú¸ì=" << getVolume()
        << ", ïëîùàäü ïîâåðõíîñòè=" << getSurfaceArea()
        << "]; Âåðøèíû: " << p1 << " - " << p2;
    return ss.str();
}

void Parallelipiped::read(std::istream& is) {
    int choice;
    std::cout << "Âûáåðèòå ñïîñîá ñîçäàíèÿ:\n"
        << "1 - ïî òð¸ì âåðøèíàì (îáùàÿ âåðøèíà + ñìåæíûå ïî X, Y, Z)\n"
        << "2 - ïî âåðøèíå è ðàçìåðàì (äëèíà øèðèíà âûñîòà)\n"
        << "3 - ïî äâóì âåðøèíàì ãëàâíîé äèàãîíàëè (ìèíèìàëüíàÿ è ìàêñèìàëüíàÿ)\n"
        << "4 - ïî 12 êîîðäèíàòàì (x1 y1 z1 x2 y2 z2 x3 y3 z3 x4 y4 z4)\n";
    is >> choice;

    switch (choice) {
    case 1: {
        Point v1, v2, v3, v4;
        std::cout << "Ââåäèòå 4 âåðøèíû (x y z äëÿ êàæäîé):\n";
        is >> v1 >> v2 >> v3 >> v4;
        *this = Parallelipiped(v1, v2, v3, v4);
        break;
    }
    case 2: {
        Point vertex;
        double l, w, h;
        std::cout << "Ââåäèòå âåðøèíó (x y z), çàòåì äëèíó, øèðèíó, âûñîòó:\n";
        is >> vertex >> l >> w >> h;
        *this = Parallelipiped(vertex, l, w, h);
        break;
    }
    case 3: {
        Point minV, maxV;
        std::cout << "Ââåäèòå ìèíèìàëüíóþ âåðøèíó (x y z) è ìàêñèìàëüíóþ âåðøèíó (x y z):\n";
        is >> minV >> maxV;
        *this = Parallelipiped(minV, maxV);
        break;
    }
    case 4: {
        double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
        std::cout << "Ââåäèòå 12 êîîðäèíàò (x1 y1 z1 x2 y2 z2 x3 y3 z3 x4 y4 z4):\n";
        is >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;
        *this = Parallelipiped(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4);
        break;
    }
    default:
        throw std::invalid_argument("Íåâåðíûé ñïîñîá ñîçäàíèÿ");
    }
}

Parallelipiped Parallelipiped::readFrom(std::istream& is) {
    Parallelipiped p;
    p.read(is);
    return p;
}
