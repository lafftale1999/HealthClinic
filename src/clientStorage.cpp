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

void ClientStorage::createClients(int amount)
{
    std::cout << "CREATING CLIENTS" << std::endl;

    auto begin = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < amount; i++)
    {
        this->addClient(std::to_string(i));
    }

    srand(time(NULL));

    for(int i = this->getList().size() - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        //Shuffle
        std::swap(this->getList()[i], this->getList()[j]);
    }

    auto finish = std::chrono::high_resolution_clock::now();

    std::cout << "CLIENT CREATION TOOK: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - begin).count() << " milliseconds." << std::endl << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void ClientStorage::writeClientsToFile()
{
    std::cout << "WRITING CLIENTS TO FILE" << std::endl;
    auto begin = std::chrono::high_resolution_clock::now();

    std::ofstream File(CLIENT_PATH);

    for(Client& client : this->clients)
    {
        File << client.getClientId() << std::endl;
    }

    File.close();

    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "WRITING TO FILE TOOK: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - begin).count() << " milliseconds." << std::endl << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

bool ClientStorage::readClientsFromFile()
{
    std::cout << "READING CLIENTS FROM FILE" << std::endl;
    auto begin = std::chrono::high_resolution_clock::now();

    std::ifstream File(CLIENT_PATH);
    std::string temp;

    if(!File) 
    {
        std::cout << "FILE not found" << std::endl;
        return false;
    }

    if(File.is_open())
    {
        File.seekg(0, std::ios::end);
        if(File.tellg() == 0)
        {
            std::cout << "File is empty, creating clients" << std::endl;
            return false;
        }
    }

    while(std::getline(File, temp))
    {
        clients.emplace_back(temp);
    }

    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << "READING CLIENTS FROM FILE TOOK: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish - begin).count() << " milliseconds." << std::endl << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));

    return true;
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