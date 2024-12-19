#include "../include/client.h"

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
    this->clientId = clientId;
}

std::string Client::getClientId()
{
    return this->clientId;
}
// Comparison operator for sorting
bool Client::operator<(const Client& other) const
{
    return this->clientId < other.clientId;  // Compare based on clientId
}