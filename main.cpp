#include "include/clientStorage.h"
#include "include/clinic.h"
#include "include/queue.h"
#include <iostream>

int main()
{
    int amount = 10000;
    Clinic clinic(amount, CREATE);
    
    int checksum = 0;

    for(int i = 0; i < 10000; i++)
    {
        for(Client& client : clinic.getClients().getList())
        {   
            Client temp = Client(std::to_string(i));
            if(temp.getClientId() == client.getClientId())
            {
                checksum++;
                break;
            }
        }

    }

    std::cout << checksum << std::endl;
    
    return 0; 
}

