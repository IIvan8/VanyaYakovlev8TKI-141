#include "Oval.h"
#include "Point.h"
#include <iostream>
#include <sstream>
#include <string>

bool Oval::isValid() const {
    if (radiusX <= 0 || radiusY <= 0) return false;

    if (center.getX() + radiusX > maxCoordinate ||
        center.getY() + radiusY > maxCoordinate ||
        center.getX() < radiusX ||
        center.getY() < radiusY) {
        return false;
    }

    return true;
}

Oval::Oval(const Point& center, double rx, double ry, double maxCoord)
    : center(center), radiusX(fabs(rx)), radiusY(fabs(ry)), maxCoordinate(maxCoord) {
    if (!isValid()) {
        throw std::invalid_argument("Недопустимые параметры овала");
    }
}

std::string Oval::toString() const {
    std::stringstream ss;
    ss << "Овал с центром в " << center
        << ", горизонтальным радиусом " << radiusX
        << " и вертикальным радиусом " << radiusY;
    return ss.str();
}

Oval Oval::ReadFromInput(double maxCoord) {
    std::cout << "Введите координаты центра овала (формат: x y): ";
    Point center;
    std::cin >> center;

    std::cout << "Введите горизонтальный радиус: ";
    double rx;
    std::cin >> rx;

    std::cout << "Введите вертикальный радиус: ";
    double ry;
    std::cin >> ry;

    return Oval(center, rx, ry, maxCoord);
}

void Oval::readFromInput() {
    *this = ReadFromInput(maxCoordinate);
}

std::ostream& operator<<(std::ostream& os, const Oval& oval) {
    os << oval.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Oval& oval) {
    oval.readFromInput();
    return is;
}