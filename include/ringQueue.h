#ifndef __OUR_RING_QUEUE_H
#define __OUR_RING_QUEUE_H

#include <iostream>
#include <optional>

template <typename T, size_t N>
class RingQueue
{
    T queue[N];
    size_t head;
    size_t tail;
    size_t size;
    bool isFull;

public:
    RingQueue():head(0), tail(0), size(0), isFull(false){}

    std::optional<T> pop()
    {
        if(size == 0)
        {
            std::cout << "Nothing in queue" << std::endl;
            return std::nullopt;
        }

        T item = queue[head];
        head = (head + 1) % N;

        size--;
        isFull = false;
        
        return item;
    }

    void push(T item)
    {
        queue[tail] = item;
        tail = (tail + 1) % N;

        if(size < 10) size++;
        else if (size == 10) isFull = true;
    }

    bool getIsFull()
    {
        return this->isFull;
    }

    size_t getSize()
    {
        return this->size;
    }

    T* getQueue()
    {
        return this->queue;
    }

    void printQueue()
    {
        for(size_t i = 0; i < size; i++)
        {
            std::cout << i << ": " << queue[(head + i) % N] << std::endl;
        }
    }
};

#endif