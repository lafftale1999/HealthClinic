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
    T data[SIZE];                   // Static array to store data
    size_t front;                   // Pointer for first element
    size_t end;                     // Pointer for last element
    size_t count;                   // Amount of elements in array
    size_t span;                    // Span for random numbers when adding to queue
    std::mutex mtx;                 // Software mechanism to ensure two threads can't access the same resource at the same time
    std::condition_variable cv;     // Software mechanism for controlling threads
    std::atomic<bool> stop = false; // Variable for controlling when to stop threads

public:
    // Konstruktor
    Queue() : front(0), end(0), count(0) {}

    // Destruktor
    ~Queue()
    {
        // Aquire the mutex and lock while we are changing the stop variable
        {
            std::unique_lock<std::mutex> lock(this->mtx);
            stop = true; // Signal that the threads are stopping
        }

        // Notify all threads
        this->cv.notify_all(); // Väcka alla väntande trådar
    }

    void addToQueue()
    {
        // Seeding our random generator
        srand(time(NULL));

        // Put everything in a try catch block for security
        try {

            // Aquire the mutex while we use the queue
            std::unique_lock<std::mutex> lock(this->mtx);

            // Infinite while-loop while program is running
            while (true)
            {
                // Condition variable - sleeps the thread until the lambda function returns true
                this->cv.wait(lock, [this] {
                    return this->size() < SIZE || stop;
                });

                // If the program is done - exiting the loop
                if (stop)
                {
                    break;
                }

                // creates a random number in span
                int rnd = rand() % this->span;

                // Adds it to queue and checks if it was successful
                if (!this->enqueue(rnd)) std::cout << "[addToQueue] Client add failed (queue full)" << std::endl;

                // Notify the other thread
                this->cv.notify_one();
            }
        }

        catch (const std::exception& e)
        {
            std::cerr << "[addToQueue] Exception: " << e.what() << std::endl;
        }
    }

    T getFromQueue()
    {
        // Put everything in a try-catch block for security
        try
        {
            // Aquire the mutex and lock
            std::unique_lock<std::mutex> lock(this->mtx);

            // Sleep the thread until the lambda expression returns true
            this->cv.wait(lock, [this] {
                return this->size() > 0 || stop;
            });

            // Check if the thread should be running
            if (stop && this->size() == 0)
            {
                std::cout << "[getFromQueue] Stop flag detected and queue is empty" << std::endl;
                throw std::runtime_error("Queue stopped and empty");
            }

            // Get item from queue
            T item = this->data[this->front];

            // Remove item from queue
            this->dequeue(this->data[front]);

            // Notify thread to check their condition variable
            this->cv.notify_one();

            return item;
        }
        
        catch (const std::exception& e)
        {
            std::cerr << "[getFromQueue] Exception: " << e.what() << std::endl;
            throw; // Pass on the exception
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