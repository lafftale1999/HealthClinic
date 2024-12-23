#include "queue.h"
#include <iostream>

template <typename T, size_t Size>
bool Queue<T, Size>::push(const T& value) {
    if ((static_cast<size_t>(rear) + 1) % Size == static_cast<size_t>(front)) {
        std::cout << "Queue is full" << std::endl;
        return false;
    }
    rear = (static_cast<size_t>(rear) + 1) % Size;
    arr[rear] = value;
    if (front == -1) front = 0;
    return true;
}

template <typename T, size_t Size>
bool Queue<T, Size>::pop(T& value) {
    if (front == -1) {
        return false;
    }
    value = arr[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (static_cast<size_t>(front) + 1) % Size;
    }
    return true;
}

template class Queue<int, 5>;
