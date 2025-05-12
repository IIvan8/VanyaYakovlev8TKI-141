#pragma once
#include <iostream>

/**
* @class Point.
* @brief Класс, представляющий точку на двумерной плоскости.
*/
class Point {
private:
    /**
    * @param x Координата точки.
    */
    double x;

    /**
    * @param y Координата точки.
    */
    double y;

public:

    /**
    * @brief Конструктор точки.
    * @param x Координата x (по умолчанию 0).
    * @param y Координата y (по умолчанию 0).
    */
    Point(double x = 0, double y = 0);

    /**
    * @brief Получить координату x.
    * @return Значение координаты x.
    */
    double getX() const;
    
    /**
    * @brief Получить координату y.
    * @return Значение координаты y.
    */
    double getY() const;

    /**
    * @brief Оператор сравнения на равенство.
    * @param other Сравниваемая точка.
    * @return true если точки равны, в противном случае false.
    */
    bool operator==(const Point& other) const;

    /**
    * @brief Оператор сравнения на неравенство.
    * @param other Сравниваемая точка.
    * @return true если точки не равны, в противном случае false.
    */
    bool operator!=(const Point& other) const;

    /**
    * @brief Оператор вывода точки в поток.
    * @param os Выходной поток.
    * @param point Точка для вывода.
    * @return Поток os.
    */
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    /**
    * @brief Оператор ввода точки из потока.
    * @param is Входной поток.
    * @param point Точка для ввода.
    * @return Поток is.
    */
    friend std::istream& operator>>(std::istream& is, Point& point);
};
