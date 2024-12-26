#include "../include/clinic.h"
#include <iostream>
#include <thread>

Clinic::Clinic(int amountOfClients, Command c)
{
    if(this->clients.getList().size() != amountOfClients || this->clients.getList().empty() || c == CREATE)
    {
        Client::length = amountOfClients;
        if(this->clients.getList().size()) this->clients.getList().erase(this->clients.getList().begin(), this->clients.getList().end());
        this->clients.createClients(amountOfClients);
        this->clients.writeClientsToFile();
    }

    else this->clients.readClientsFromFile();

    this->queue.setSpan(amountOfClients);
}

void Clinic::runClinic()
{
    std::thread queueThread([this] {this->queue.addToQueue();});
}

ClientStorage& Clinic::getClients()
{
    return this->clients;
}

void Clinic::addClient(std::string clientId){
    Client newClient(clientId);
    this->clients.addClient(newClient);
}