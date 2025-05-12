#include "../Task.3.decision/Oval.h"
#include <locale>
#include <iostream>
#include <sstream>

Oval readOvalFromStream(std::istream& input, double MAX_COORD);

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        const double MAX_COORD = 1920;

        std::cout << "=== ¬вод первого овала ===" << std::endl;
        Oval oval1 = readOvalFromStream(std::cin, MAX_COORD);
        oval1.draw();

    }
    catch (const std::exception& e) {
        std::cerr << "ќшибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

Oval readOvalFromStream(std::istream& input, double MAX_COORD) {
    std::cout << "¬ведите координаты центра овала (формат: (x y)): ";
    double centerX, centerY;
    input >> centerX >> centerY;

    std::cout << "¬ведите горизонтальный и вертикальный радиусы (формат: rx ry): ";
    double radiusX, radiusY;
    input >> radiusX >> radiusY;

    return Oval(Point(centerX, centerY), radiusX, radiusY, MAX_COORD);
}