#ifndef CLINIC_H
#define CLINIC_H

#include "clientStorage.h"

typedef enum
{
    CREATE,
    N_CREATE
}Command;


class Clinic
{
    ClientStorage clients;

public:
    Clinic(int amountOfClients, Command c);
    ClientStorage& getClients();
    void addClient(std::string clientId);
};

#endif