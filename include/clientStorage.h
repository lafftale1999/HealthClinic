#ifndef CLIENT_STORAGE_H
#define CLIENT_STORAGE_H

#include "client.h"
#include <vector>

#define CLIENT_PATH "data/clients.txt"

class ClientStorage
{
    std::vector<Client> clients;

public:
    ClientStorage();
    void createClients(int amount);
    void writeClientsToFile();
    bool readClientsFromFile();

    void addClient(std::string clientId);
    Client& getClient(int index);
    std::vector<Client>& getList();
    Client* binarySearch(Client target);
    void sortClients();
};

#endif