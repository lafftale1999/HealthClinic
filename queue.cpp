#include <iostream> 
#include "queue.h"
#include <queue>


template <typename T, size_t SIZE>
class Queue {
private:
    T data[SIZE];  // Statisk array för att lagra ködata
    size_t front;  // Pekare för första elementet
    size_t end;   // Pekare för sista elementet
    size_t count;  // Antal element i kön

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
};

int main() {
    // Skapa en kö med kapacitet 5
    Queue<int, 5> q;

    // Testa att lägga till och ta bort element
    if (q.enqueue(10)) {
        std::cout << "Enqueued 10\n";
    } else {
        std::cout << "Failed to enqueue 10\n";
    }

    if (q.enqueue(20)) {
        std::cout << "Enqueued 20\n";
    } else {
        std::cout << "Failed to enqueue 20\n";
    }

    int value;
    if (q.dequeue(value)) {
        std::cout << "Dequeued: " << value << "\n";
    } else {
        std::cout << "Failed to dequeue\n";
    }

    return 0;
};
