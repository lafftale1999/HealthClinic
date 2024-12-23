#ifndef CLIENT_H
#define CLIENT_H

#include <string>


class Client
{
private: 
    std::string clientId;
    static const size_t ID_LENGTH = 2; // Standard length for patients ID.

public:
    Client();//Constructor
    explicit Client(std::string clientId);// Constructor with parameter.
    Client(const Client& other); // Copy constructor

    
    void setClientId(std::string clientId);
    std::string getClientId();
    std::string padClientId(std::string id);//helper function for padding.
};

#endif