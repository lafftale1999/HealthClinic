#include "clinic.h"

Clinic::Clinic()
{

}

ClientStorage& Clinic::getClients()
{
    return this->clients;
}

void Clinic::addClient(std::string clientId){
    Client newClient(clientId);
    this->clients.addClient(newClient);

}