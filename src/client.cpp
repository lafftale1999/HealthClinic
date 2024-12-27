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
}

std::string Client::padClientId(std::string id){
    return std::string(std::to_string(Client::length).length() - id.length(), '0') + id; 
}

std::string Client::getClientId()
{
    return this->clientId;
}

bool Client::operator<(const Client& other) const
{
    return this->clientId < other.clientId;
}