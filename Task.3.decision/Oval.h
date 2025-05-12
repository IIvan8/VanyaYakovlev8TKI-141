#pragma once
#include "Shape.h"
#include "Point.h"
#include <stdexcept>

class Oval : public Shape {
private:
    Point center;
    double radiusX;
    double radiusY;
    double maxCoordinate;

   /**
    * @brief Проверяет валидность параметров овала.
    * @return true если овал валиден, в противном случае false.
    */
    bool isValid() const;

public:
    /**
     * @brief Конструктор овала.
     * @param center Центр овала.
     * @param rx Горизонтальный радиус.
     * @param ry Вертикальный радиус.
     * @param maxCoord Максимально допустимая координата.
     */
    Oval(const Point& center, double rx, double ry, double maxCoord);

    /**
    * @brief Преобразует овал в строковое представление.
    * @return Строка в формате "Овал с центром в (x,y), горизонтальным радиусом X и вертикальным радиусом Y".
    */
    std::string toString() const override;

    /**
    * @brief Статический метод для создания овала через пользовательский ввод.
    * @param maxCoord Максимально допустимая координата.
    * @return Созданный объект Oval.
    */
    static Oval ReadFromInput(double maxCoord);
    /**
    * @brief Чтение параметров овала из пользовательского ввода.
    */
    void readFromInput() override;

    /**
     * @brief Оператор вывода овала в поток.
     * @param os Выходной поток.
     * @param oval Объект Oval для вывода.
     * @return Поток os.
     */
    friend std::ostream& operator<<(std::ostream& os, const Oval& oval);

    /**
    * @brief Оператор ввода овала из потока.
    * @param is Входной поток.
    * @param oval Объект Oval для заполнения.
    * @return Поток is.
    */
    friend std::istream& operator>>(std::istream& is, Oval& oval);
};
