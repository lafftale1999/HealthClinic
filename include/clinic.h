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
    Clinic(unsigned int amountOfClients, Command c);
    void runClinic();
    ClientStorage& getClients();
};

#endif