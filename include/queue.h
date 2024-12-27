#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>

template <typename T, size_t SIZE>
class Queue {
private:
    T data[SIZE];  // Statisk array för att lagra ködata
    size_t front;  // Pekare för första elementet
    size_t end;   // Pekare för sista elementet
    size_t count;  // Antal element i kön
    size_t span;
    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<bool> stop = false;

public:
    // Konstruktor
    Queue() : front(0), end(0), count(0) {}

    ~Queue()
    {
        {
            std::unique_lock<std::mutex> lock(this->mtx);
            stop = true; // Signalera avslutning
        }
        this->cv.notify_all(); // Väcka alla väntande trådar
        std::cout << "[Queue] Destructor called, stop flag set" << std::endl;
    }

    void addToQueue()
    {
        srand(time(NULL));

        try {
            std::unique_lock<std::mutex> lock(this->mtx);

            while (true)
            {
                this->cv.wait(lock, [this] {
                    return this->size() < SIZE || stop;
                });

                if (stop)
                {
                    std::cout << "[addToQueue] Stop flag detected, exiting loop" << std::endl;
                    break;
                }

                int rnd = rand() % this->span;

                if (!this->enqueue(rnd)) std::cout << "[addToQueue] Client add failed (queue full)" << std::endl;

                this->cv.notify_one();
            }

            std::cout << "[addToQueue] Finished processing queue" << std::endl;
        }

        catch (const std::exception& e)
        {
            std::cerr << "[addToQueue] Exception: " << e.what() << std::endl;
        }
    }

    T getFromQueue()
    {
        try
        {
            std::unique_lock<std::mutex> lock(this->mtx);

            this->cv.wait(lock, [this] {
                return this->size() > 0 || stop;
            });

            if (stop && this->size() == 0)
            {
                std::cout << "[getFromQueue] Stop flag detected and queue is empty" << std::endl;
                throw std::runtime_error("Queue stopped and empty");
            }

            T item = this->data[this->front];

            this->dequeue(this->data[front]);

            this->cv.notify_one();

            return item;
        }
        
        catch (const std::exception& e)
        {
            std::cerr << "[getFromQueue] Exception: " << e.what() << std::endl;
            throw; // Vidarebefordra undantaget
        }
    }

    bool enqueue(const T& item)
    {
        if (count == SIZE)
        {
            std::cout << "[enqueue] Queue is full, cannot add item" << std::endl;
            return false; // Kön är full
        }

        this->data[end] = item;
        end = (end + 1) % SIZE; // Cirkulär hantering
        count++;

        return true;
    }

    // Metod för att ta bort element från kön (dequeue)
    bool dequeue(T& item)
    {

        if (count == 0)
        {
            std::cout << "[dequeue] Queue is empty, cannot remove item" << std::endl;
            return false; // Kön är tom
        }

        item = data[front];
        front = (front + 1) % SIZE; // Cirkulär hantering
        count--;

        return true;
    }

    // Metod för att kolla om kön är tom
    bool isEmpty() const {
        return count == 0;
    }

    // Metod för att kolla om kön är full
    bool isFull() const {
        return count == SIZE;
    }

    // Metod för att få antalet element i kön
    size_t size() const {
        return count;
    }

    // getters
    T* getArray()
    {
        return this->data;
    }

    T& getData(int index)
    {
        return this->data[index];
    }

    void setSpan(size_t span)
    {
        this->span = span;
    }
};

#endif