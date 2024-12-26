#include "../include/clinic.h"
#include <iostream>

Clinic::Clinic(int amountOfClients, Command c)
{
    if(!this->clients.getList().size() || c == CREATE)
    {
        Client::length = amountOfClients;
        if(this->clients.getList().size()) this->clients.getList().erase(this->clients.getList().begin(), this->clients.getList().end());
        this->clients.createClients(amountOfClients);
        this->clients.writeClientsToFile();
    }

    else this->clients.readClientsFromFile();
}

ClientStorage& Clinic::getClients()
{
    return this->clients;
}

void Clinic::addClient(std::string clientId){
    Client newClient(clientId);
    this->clients.addClient(newClient);
}