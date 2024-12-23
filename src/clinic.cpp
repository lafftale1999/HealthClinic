#include "../include/clinic.h"

Clinic::Clinic(int amountOfClients, Command c)
{
    switch (c)
    {
    case CREATE:
        Client::length = amountOfClients;
        this->clients.createClients(amountOfClients);
        break;
    
    default:
        break;
    }
}

ClientStorage& Clinic::getClients()
{
    return this->clients;
}

void Clinic::addClient(std::string clientId){
    Client newClient(clientId);
    this->clients.addClient(newClient);
}