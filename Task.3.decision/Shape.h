#pragma once
#include <string>

/**
* @brief Абстрактный базовый класс для геометрических фигур.
*/
class Shape {
public:
    /**
    * @brief Виртуальный деструктор.
    */
    virtual ~Shape() = default;

    /**
    * @brief Возвращает строковое представление фигуры.
    * @return Строка с описанием фигуры.
    */
    virtual std::string toString() const = 0;

    /**
    * @brief Выводит описание фигуры в стандартный вывод.
    */
    void draw() const;

    /**
    * @brief Чтение параметров фигуры из пользовательского ввода.
    */
    virtual void readFromInput() = 0;
};