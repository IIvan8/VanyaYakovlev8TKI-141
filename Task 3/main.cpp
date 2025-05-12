#include "../Task.3.decision/Oval.h"
#include <locale>
#include <iostream>
#include <sstream>

/**
* @brief Чтение параметров овала из входного потока.
* @param input Входной поток для чтения.
* @param MAX_COORD Максимально допустимое значение координаты.
* @return Объект Oval, созданный из введенных данных.
*/
Oval readOvalFromStream(std::istream& input, double MAX_COORD);

/**
* @brief Точка входа в программу.
* @return 0 при успешном выполнении, при ошибке 1.
*/
int main() {
    setlocale(LC_ALL, "Russian");
    try {
        const double MAX_COORD = 1920;

        std::cout << "=== Ввод первого овала ===" << std::endl;
        Oval oval1 = readOvalFromStream(std::cin, MAX_COORD);
        oval1.draw();

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

/**
* @brief Реализация функции readOvalFromStream.
*/
Oval readOvalFromStream(std::istream& input, double MAX_COORD) {
    std::cout << "Введите координаты центра овала (формат: (x y)): ";
    double centerX, centerY;
    input >> centerX >> centerY;

    std::cout << "Введите горизонтальный и вертикальный радиусы (формат: rx ry): ";
    double radiusX, radiusY;
    input >> radiusX >> radiusY;

    return Oval(Point(centerX, centerY), radiusX, radiusY, MAX_COORD);
}