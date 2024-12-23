#include "client.h"
#include <string>

//Padding helper function.
std::string Client::padClientId(std::string id){
    const size_t ID_LENGTH = 2; // 2 digits.
    return std::string(ID_LENGTH - id.length(), '0') + id; //Added leading zero. 
}

Client::Client(const Client& other){
    this->clientId = other.clientId;
}

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
    this->clientId = padClientId(clientId); //Pad the ID before storing it.
}

std::string Client::getClientId()
{
    return this->clientId;
}