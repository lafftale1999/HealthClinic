#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

template <typename T, size_t Size>
class Queue {
    T arr[Size];
    int front = -1;
    int rear = -1;

public:
    bool push(const T& value);
    bool pop(T& value);
};

#endif // QUEUE_H
