#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <mutex>
#include <condition_variable>

template <typename T, size_t SIZE>
class Queue {
private:
    T data[SIZE];  // Statisk array för att lagra ködata
    size_t front;  // Pekare för första elementet
    size_t end;   // Pekare för sista elementet
    size_t count;  // Antal element i kön
    std::mutex mtx;
    std::condition_variable cv;

public:
    // Konstruktor
    Queue() : front(0), end(0), count(0) {}

    // Metod för att lägga till element i kön (enqueue)
    bool enqueue(const T& item) {
        if (count == SIZE) {  // Om kön är full, kan vi inte lägga till fler element
            return false;  // Felkod - kön är full
        }
        data[end] = item;  // Lägg till elementet i slutet av kön
        end = (end + 1) % SIZE;  // Flytta end pekaren, med cirkulär hantering
        count++;  // Öka antalet element
        return true;
    }

    // Metod för att ta bort element från kön (dequeue)
    bool dequeue(T& item) {
        if (count == 0) {  // Om kön är tom, kan vi inte ta bort något element
            return false;  // Felkod - kön är tom
        }
        item = data[front];  // Ta det första elementet från kön
        front = (front + 1) % SIZE;  // Flytta front pekaren, med cirkulär hantering
        count--;  // Minska antalet element
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
};

#endif