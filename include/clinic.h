#ifndef CLINIC_H
#define CLINIC_H

#include "clientStorage.h"
#include "queue.h"
#include "terminalGUI.h"

#include <thread>

typedef enum
{
    CREATE,
    N_CREATE
}Command;


class Clinic
{
    ClientStorage clients;
    Queue<int, 10> queue;
    TerminalGUI GUI;
    std::thread queueThread;
    std::thread clinicThread;
    

public:
    Clinic(unsigned int amountOfClients, Command c);
    void runClinic();
    void openClinic();
    ClientStorage& getClients();
    void stopClinic();
};

#endif