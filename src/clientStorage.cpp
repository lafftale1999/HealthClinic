#include "../include/clientStorage.h"
#include <ctime>

ClientStorage::ClientStorage()
{

}

void ClientStorage::addClient(Client client)
{
    this->clients.push_back(client);
}

void ClientStorage::createClients(int amount)
{
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
