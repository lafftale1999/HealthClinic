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
