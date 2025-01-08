#include "../include/client.h"
#include <string>

int Client::length = 0;

Client::Client()
{
    this->clientId = "Error";
}

Client::Client(std::string clientId)
{
    this->setClientId(clientId);
}

void Client::setClientId(std::string clientId)
{
    this->clientId = padClientId(clientId);
<<<<<<< HEAD
=======
}

// Rimsha
std::string Client::padClientId(std::string id){
    return std::string(std::to_string(Client::length).length() - id.length(), '0') + id; 
>>>>>>> b7a00273e9919284fe64570a580b9233150ace92
}

// Rimsha
//0-padding on a client ID string.
//all client IDs -> consistent length by adding leading zeros.
std::string Client::padClientId(std::string id){
    return std::string(std::to_string(Client::length).length() - id.length(), '0') + id; 
}
//getter method
std::string Client::getClientId()
{
    return this->clientId;
}
<<<<<<< HEAD
//sorting and using Clients in ordered containers.
=======

>>>>>>> b7a00273e9919284fe64570a580b9233150ace92
bool Client::operator<(const Client& other) const
{
    return this->clientId < other.clientId;
}