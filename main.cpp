#include "include/clinic.h"
#include "binarySearch.h"
#include "queue.h"
#include <iostream>
#include <fstream>
#include <iomanip> // For std::setw and std::setfill
#include <algorithm>
#include <chrono>

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <Windows.h> // For Sleep (Windows)

void addmyclientsfromfile(Clinic &clinic)
{
    
    std::string line;
    int addedclientcount = 0;
    auto startTime = std::chrono::high_resolution_clock::now();
    // Open the randomNumbers.txt file and load the data into the vector
    std::ifstream orginalfile("randomNumbers.txt");
    if (!orginalfile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
    }
    // Read each line until EOF and add clients
    while (std::getline(orginalfile, line)) {
        try {
            if (line.empty()) {
                std::cerr << "Warning: Empty line encountered at line " << addedclientcount + 1 << "." << std::endl;
                continue;  // Skip empty lines
            }
            
            clinic.getClients().addClient(Client(line));
            addedclientcount++;
        } 
        catch (const std::exception& e) {
            std::cerr << "Error processing line " << addedclientcount + 1 << ": " << e.what() << std::endl;
        }
    }
    orginalfile.close();
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cout << "READING AND ADDING Took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count() << " nanoseconds" << std::endl;
    // std::cout << "Successfully processed " << addedclientcount << " clients from the file." << std::endl;
// sorting the clients
    std::cout << "SORTING: " << std::endl;
    startTime = std::chrono::high_resolution_clock::now();
    std::sort(clinic.getClients().getList().begin(), clinic.getClients().getList().end()); 
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << "SORTING Took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime    - startTime).count() << " nanoseconds" << std::endl;

   /* std::string target = "415826";
    startTime = std::chrono::high_resolution_clock::now();
    Client* result = binarySearch(clinic.getClients().getList(), target);
    endTime = std::chrono::high_resolution_clock::now();
    std::cout << "BINARY SEARCH Took: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count() << " nanoseconds" << std::endl;
    
    if (result != nullptr) {
        std::cout << "Found client with ID: " << result->getClientId() << std::endl;        
        // result->setClientId("111111");
        // std::cout << "Found client replaced with ID: " << result->getClientId() << std::endl;
    } else {
        std::cout << "Client not found" << std::endl;
    }
    
    // std::sort(clinic.getClients().getList().begin(), clinic.getClients().getList().end()); 

    // change the client ID to 111111 in the sorted.txt file
     std::ofstream sorted("sorted.txt");
    for (Client client : clinic.getClients().getList()) {
        sorted << client.getClientId() << std::endl;
    }
    sorted.close();*/
}
void initializeRandomSeed() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed rand() with the current time
}
int main()
{
    
    Clinic clinic;
    addmyclientsfromfile(clinic);
    Queue<int, 5> queue; // Create a queue of integers with size 5
    initializeRandomSeed();
    while (true) {
        int operation = std::rand() % 2;  
        
        if (operation == 0) {
            // Push operation: Randomly select a client ID from the clinic's client list and push to the queue
            if (clinic.getClients().getList().empty()) {
                std::cout << "No clients in the clinic." << std::endl;
                continue;
            }

            // Randomly select a client from the clinic list
            int randomIndex = std::rand() % clinic.getClients().getList().size();            
            int clientId = std::stoi(clinic.getClients().getList()[randomIndex].getClientId());
            //  Client& clientp = clinic.getClients().getList()[randomIndex];
            // int clientId = std::stoi(clientp.getClientId());

            if (queue.push(clientId)) {
                std::cout << "Pushed: " << clientId << std::endl;
            } else {
                std::cout << "Queue is full, could not push." << std::endl;
            }
        } else {
            // Pop operation: Pop the first element from the queue
            int poppedValue;
            if (queue.pop(poppedValue)) {
                std::cout << "Pop: " << poppedValue << std::endl;
            } else {
                std::cout << "Queue is empty, could not pop." << std::endl;
            }
        }
        
        Sleep(1000); 
        
    }


return 0;
}