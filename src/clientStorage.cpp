#include "../include/clientStorage.h"

ClientStorage::ClientStorage()
{

}

void ClientStorage::addClient(Client client)
{
    this->clients.push_back(client);
}

Client& ClientStorage::getClient(int index)
{
    return this->clients[index];
}

std::vector<Client>& ClientStorage::getList()
{
    return this->clients;
}