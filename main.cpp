#include "include/clinic.h"
#include "include/queue.h"

    int main() {
        
        Queue<Client, 10> queue;

        for(int i = 0; i < 10; i++)
        {
            queue.enqueue(std::to_string(i));
        }

        return 0; 
    }