#pragma once
#include <initializer_list>
#include <utility> 

class PriorityQueue {
private:
    struct Node {
        int value;
        int priority;
        Node* next;

        Node(int val, int prio) : value(val), priority(prio), next(nullptr) {}
    };

    Node* head;
    size_t size;
public:
    /**
    * @brief Конструктор по умолчанию. Создает пустую очередь.
    */
    PriorityQueue();

    /**
    * @brief Конструктор с инициализацией из списка
    * @param initList Список пар {значение, приоритет} для инициализации
    */
    PriorityQueue(std::initializer_list<std::pair<int, int>> initList);

    /**
    * @brief Конструктор копирования
    * @param other Очередь для копирования
    */
    PriorityQueue(const PriorityQueue& other);

    /**
    * @brief Конструктор перемещения
    * @param other Очередь для перемещения
    */
    PriorityQueue(PriorityQueue&& other) noexcept;

    /**
    * @brief Деструктор. Очищает память от всех узлов.
    */
    ~PriorityQueue();

    /**
    * @brief Оператор копирующего присваивания
    * @param other Очередь для копирования
    * @return Ссылка на текущую очередь
    */
    PriorityQueue& operator=(const PriorityQueue& other);

    /**
    * @brief Оператор перемещающего присваивания
    * @param other Очередь для перемещения
    * @return Ссылка на текущую очередь
    */
    PriorityQueue& operator=(PriorityQueue&& other) noexcept;

    /**
    * @brief Добавляет элемент в очередь
    * @param value Значение элемента
    * @param priority Приоритет элемента
    */
    void insert(int value, int priority);

    /**
    * @brief Извлекает элемент с максимальным приоритетом
    * @return Значение элемента с наивысшим приоритетом
    */
    int extractMax();

    /**
    * @brief Возвращает элемент с максимальным приоритетом без извлечения
    * @return Значение элемента с наивысшим приоритетом
    */
    int findMax() const;

    /**
    * @brief Проверяет, пуста ли очередь
    * @return true если очередь пуста, false иначе
    */
    bool isEmpty() const;

    /**
    * @brief Возвращает размер очереди
    * @return Количество элементов в очереди
    */
    size_t getSize() const;

    /**
    * @brief Преобразует очередь в строку (для отладки)
    * @return Строковое представление очереди
    */
    std::string toString() const;

    /**
    * @brief Очищает очередь
    */
    void clear();
};

/**
* @brief Оператор вставки элемента в очередь
* @param queue Очередь для вставки
* @param element Пара {значение, приоритет}
* @return Ссылка на измененную очередь
*/
PriorityQueue& operator<<(PriorityQueue& queue, const std::pair<int, int>& element);

/**
* @brief Оператор извлечения элемента из очереди
* @param queue Очередь для извлечения
* @param value Переменная для записи извлеченного значения
* @return Ссылка на измененную очередь
*/
PriorityQueue& operator>>(PriorityQueue& queue, int& value);