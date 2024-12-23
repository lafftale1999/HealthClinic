#ifndef CLIENT_STORAGE_H
#define CLIENT_STORAGE_H

#include "client.h"
#include <vector>

class ClientStorage
{
private:
    std::vector<Client> clients;

public:
    ClientStorage();
    void addClient(Client client);
    Client& getClient(int index);
    std::vector<Client>& getList();

    void createClients();
};

#endif