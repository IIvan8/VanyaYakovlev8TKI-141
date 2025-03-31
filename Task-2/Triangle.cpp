#include <cmath>
#include <iostream>
#include "Triangle.h"
#include "Point.h"

using namespace std;

/**
*@brief Треугольник заданный тремя точками.
*/
Triangle::Triangle(const Point & a, const Point & b, const Point & c) : A(a), B(b), C(c)
{
    this->a = sideLength(B, C);
    this->b = sideLength(A, C);
    this->c = sideLength(A, B);
    check();
}

/**
*@brief  Проверка существования тругольника.
*/
void Triangle::check()
{
    if ((a == b or b == c or c == a) or ((a > (b + c)) or (b > (a + c)) or (c > (b + a)))) {
        std::cout << "Треугольник не существует";
        exit(EXIT_FAILURE);
    }
}

/**
*@brief Вычисляем длину стороны треугольника.
* @param  p1 Первая точка.
* @param  p2 Вторая точка.
*/
double Triangle::sideLength(const Point & p1, const Point & p2)
{
    return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
}

/**
*@brief Вычисляем периметр треугольника.
*/
double Triangle::perimeter()
{
    return a + b + c;
}

/**
*@brief Вычисляем координаты центра описанной окружности.
*/
Point Triangle::circumcenter()
{
    double D = 2 * (A.getX() * (B.getY() - C.getY()) + B.getX() * (C.getY() - A.getY()) + C.getX() * (A.getY() - B.getY()));

    double Ux = ((A.getX() * A.getX() + A.getY() * A.getY()) * (B.getY() - C.getY()) +
        (B.getX() * B.getX() + B.getY() * B.getY()) * (C.getY() - A.getY()) +
        (C.getX() * C.getX() + C.getY() * C.getY()) * (A.getY() - B.getY())) / D;

    double Uy = ((A.getX() * A.getX() + A.getY() * A.getY()) * (C.getX() - B.getX()) +
        (B.getX() * B.getX() + B.getY() * B.getY()) * (A.getX() - C.getX()) +
        (C.getX() * C.getX() + C.getY() * C.getY()) * (B.getX() - A.getX())) / D;

    return Point(Ux, Uy);
}