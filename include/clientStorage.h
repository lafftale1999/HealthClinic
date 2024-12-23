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
    void addClient(Client client);
    Client& getClient(int index);
    std::vector<Client>& getList();
    Client* binarySearch(std::vector<Client>& clientlist,  const std::string target);
    
};

#endif