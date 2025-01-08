#include "../include/clientStorage.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>
#include <utility>
#include <thread>
#include <algorithm>

ClientStorage::ClientStorage()
{
    this->readClientsFromFile();
}

void ClientStorage::addClient(std::string clientId)
{
    this->clients.emplace_back(clientId);
}

// Rimsha
//CLients created and initialized. 
void ClientStorage::createClients(int amount)
{
    std::cout << "CREATING CLIENTS" << std::endl;
    //Starts timing the operation using high-resolution clock(more precise timing.)
    auto begin = std::chrono::high_resolution_clock::now();
    
    //Create 'amount' number of clients.
    for(int i = 0; i < amount; i++)
    {
        //Convert to string and add as new client.
        this->addClient(std::to_string(i));
    }
    srand(time(NULL));

    //Implement shuffle algorithm.
    //Randomizes the order of all created clients.
    for(int i = this->getList().size() - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        //Shuffle: current element->swapped with randomly selected element.
        std::swap(this->getList()[i], this->getList()[j]);
    }

    //Stop timing & calculate duration. 
    auto finish = std::chrono::high_resolution_clock::now();

    //Calculate and print the total time taken in ms.
    std::cout << "CLIENT CREATION TOOK: " 
              << std::chrono::duration_cast<std::chrono::milliseconds>(finish - begin).count()
              << " milliseconds." << std::endl << std::endl;
    
    //Pause for 2 seconds.
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

// Rimsha
//file I/O operations to store clients info to the file.
void ClientStorage::writeClientsToFile()
{   
    std::cout << "WRITING CLIENTS TO FILE" << std::endl;
    //times the operation.
    auto begin = std::chrono::high_resolution_clock::now();
    //Create file stream for writing.
    std::ofstream File(CLIENT_PATH);

    //Iterate thru all clients in storage, write their ID to the file. 
    for(Client& client : this->clients)
    {
        File << client.getClientId() << std::endl;
    }

    File.close();

    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "WRITING TO FILE TOOK: " 
    << std::chrono::duration_cast<std::chrono::milliseconds>(finish - begin).count() 
    << " milliseconds." << std::endl << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

// Rimsha
//Reading clients from the file.
//bool-> true if clients were read, false if file is empty.
bool ClientStorage::readClientsFromFile()
{
    std::cout << "READING CLIENTS FROM FILE" << std::endl;
    auto begin = std::chrono::high_resolution_clock::now();

    std::ifstream File(CLIENT_PATH);
    std::string temp;

    //Checks if file exists and can be opened.
    if(!File) 
    {
        std::cout << "FILE not found" << std::endl;
        return false; // F if file cannot be opened.
    }

    //Checks if file is empty.
    if(File.is_open())
    {
        File.seekg(0, std::ios::end);
        //Checks if file position-> 0(empty file).
        if(File.tellg() == 0)
        {
            std::cout << "File is empty, creating clients" << std::endl;
            return false; //F if file is empty.
        }
    }
    
    while(std::getline(File, temp))
    {
        clients.emplace_back(temp);
    }

    //Calculate & display execution time.
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "READING CLIENTS FROM FILE TOOK: " 
              << std::chrono::duration_cast<std::chrono::milliseconds>(finish - begin).count() 
              << " milliseconds." << std::endl << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));

    return true;  //Successfully read clients from file. 
}

Client& ClientStorage::getClient(int index)
{
    return this->clients[index];
}

std::vector<Client>& ClientStorage::getList()
{
    return this->clients;
}

void ClientStorage::sortClients()
{   
    std::cout << "SORTING CLIENTS" << std::endl;
    auto begin = std::chrono::high_resolution_clock::now();

    std::sort(this->clients.begin(), this->clients.end());
    
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "SORTING CLIENTS TOOK: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - begin).count() << " milliseconds." << std::endl << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

Client* ClientStorage::binarySearch(Client target)
{
    auto begin = std::chrono::high_resolution_clock::now();

    size_t start = 0;
    size_t end = this->clients.size() - 1;

    while (start <= end)
    {
        size_t mid = start + (end - start) / 2; // Prevent overflow
        Client& midClient = this->clients.at(mid);

        if (midClient.getClientId() == target.getClientId())
        {
            auto finish = std::chrono::high_resolution_clock::now();

            std::cout << "FINDING CLIENT " << target.getClientId() <<  " TOOK: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - begin).count() << " nanoseconds." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return &midClient;
        }

        else if (midClient.getClientId() < target.getClientId())
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return nullptr;
}