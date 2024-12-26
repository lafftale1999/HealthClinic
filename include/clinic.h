#ifndef CLINIC_H
#define CLINIC_H

#include "clientStorage.h"
#include "queue.h"

typedef enum
{
    CREATE,
    N_CREATE
}Command;


class Clinic
{
    ClientStorage clients;
    Queue<int, 10> queue;

public:
    Clinic(int amountOfClients, Command c);
    void runClinic();
    ClientStorage& getClients();
    void addClient(std::string clientId);
};

#endif