#include <iostream>
#include "../decisionTask4/PriorityQueue.h"
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    PriorityQueue queue = { {8, 1}, {88, 3}, {888, 2}, {8888, 5} };
    cout << "Начальная очередь:\n" << queue.toString() << endl;
    queue << std::make_pair(88888, 4) << make_pair(888888, 0);
    cout << "После добавления элементов:\n" << queue.toString() << endl;
    cout << "Извлечение элементов в порядке приоритета:\n";
    while (!queue.isEmpty()) {
        int value = 0;
        queue >> value;
        cout << "Извлечено: " << value << endl;
    }
    if (queue.isEmpty()) {
        cout << "Очередь сейчас пуста" << endl;
    }

    return 0;
}