#include "PriorityQueue.h"
#include <string>
#include <stdexcept>

PriorityQueue::PriorityQueue() : head(nullptr), size(0) {}

PriorityQueue::PriorityQueue(std::initializer_list<std::pair<int, int>> initList) : PriorityQueue() {
    for (const auto& pair : initList) {
        insert(pair.first, pair.second);
    }
}

PriorityQueue::PriorityQueue(const PriorityQueue& other) : PriorityQueue() {
    Node* current = other.head;
    while (current != nullptr) {
        insert(current->value, current->priority);
        current = current->next;
    }
}

PriorityQueue::PriorityQueue(PriorityQueue&& other) noexcept
    : head(other.head), size(other.size) {
    other.head = nullptr;
    other.size = 0;
}

PriorityQueue::~PriorityQueue() {
    clear();
}

PriorityQueue& PriorityQueue::operator=(const PriorityQueue& other) {
    if (this != &other) {
        PriorityQueue temp(other);
        std::swap(head, temp.head);
        std::swap(size, temp.size);
    }
    return *this;
}

PriorityQueue& PriorityQueue::operator=(PriorityQueue&& other) noexcept {
    if (this != &other) {
        std::swap(head, other.head);
        std::swap(size, other.size);
    }
    return *this;
}

void PriorityQueue::insert(int value, int priority) {
    Node* newNode = new Node(value, priority);

    if (head == nullptr || priority > head->priority) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
}

int PriorityQueue::extractMax() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }

    Node* temp = head;
    int value = temp->value;
    head = head->next;
    delete temp;
    size--;
    return value;
}

int PriorityQueue::findMax() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return head->value;
}

bool PriorityQueue::isEmpty() const {
    return head == nullptr;
}

size_t PriorityQueue::getSize() const {
    return size;
}

std::string PriorityQueue::toString() const {
    std::string result;
    Node* current = head;
    while (current != nullptr) {
        result += "Value: " + std::to_string(current->value) +
            ", Priority: " + std::to_string(current->priority) + "\n";
        current = current->next;
    }
    return result;
}

void PriorityQueue::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

PriorityQueue& operator<<(PriorityQueue& queue, const std::pair<int, int>& element) {
    queue.insert(element.first, element.second);
    return queue;
}

PriorityQueue& operator>>(PriorityQueue& queue, int& value) {
    value = queue.extractMax();
    return queue;
}