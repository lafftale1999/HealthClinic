#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client
{
private: 
    std::string clientId;

public:
    static int length;
    Client();
    Client(std::string clientId);

    bool operator<(const Client& other) const;
    void setClientId(std::string clientId);
    std::string getClientId();
    std::string padClientId(std::string id);
};

#endif