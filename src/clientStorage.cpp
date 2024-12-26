#include "../include/clientStorage.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <chrono>

ClientStorage::ClientStorage()
{
    this->readClientsFromFile();
}

void ClientStorage::addClient(Client client)
{
    this->clients.push_back(client);
}

void ClientStorage::createClients(int amount)
{
    std::cout << "CREATING CLIENTS" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < amount; i++)
    {
        this->addClient(Client(std::to_string(i)));
    }

    srand(time(NULL));
    for(int i = this->getList().size() - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        //Shuffle
        Client temp = this->getClient(i);
        this->getClient(i) = this->getClient(j);
        this->getClient(j) = temp;
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "CLIENT CREATION TOOK: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds." << std::endl;
}

void ClientStorage::writeClientsToFile()
{
    std::cout << "WRITING CLIENTS TO FILE" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();

    std::ofstream File(CLIENT_PATH);

    for(Client client : this->clients)
    {
        File << client.getClientId() << std::endl;
    }

    File.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "WRITING TO FILE TOOK: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds." << std::endl;
}

bool ClientStorage::readClientsFromFile()
{
    std::cout << "READING CLIENTS FROM FILE" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();

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

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "READING CLIENTS FROM FILE TOOK: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds." << std::endl;

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

Client* ClientStorage::binarySearch(std::vector<Client>& clientlist, const std::string target)
{
    size_t start = 0;
    size_t end = clientlist.size() - 1;

    while (start <= end)
    {
        size_t mid = start + (end - start) / 2; // Prevent overflow
        Client& midClient = clientlist.at(mid);

        if (midClient.getClientId() == target)
        {
            return &midClient;
        }
        else if (midClient.getClientId() < target)
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
