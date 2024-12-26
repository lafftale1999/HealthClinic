#include "../include/clinic.h"

#include <iostream>

Clinic::Clinic(unsigned int amountOfClients, Command c)
{
    if(this->clients.getList().size() != amountOfClients || this->clients.getList().empty() || c == CREATE)
    {
        Client::length = amountOfClients;
        if(this->clients.getList().size()) this->clients.getList().erase(this->clients.getList().begin(), this->clients.getList().end());
        this->clients.createClients(amountOfClients);
        this->clients.writeClientsToFile();
    }

    else this->clients.readClientsFromFile();

    this->queue.setSpan(amountOfClients);

    this->clients.sortClients();
}

void Clinic::openClinic()
{
    queueThread = std::thread([this] {this->queue.addToQueue();});
    clinicThread = std::thread([this] {this->runClinic();});

    stopClinic();
}

void Clinic::runClinic()
{
    try
    {
        while (1)
        {
            Client temp = Client(std::to_string(this->queue.getFromQueue()));
            std::vector<std::string> messages = {"Find client", "New Client", "Exit"};
            int index = this->GUI.printMenu("SUPER HEALTHY CLINIC", "You are currently serving client: " + temp.getClientId(), messages);

            if (index == 0)
            {
                Client* clientP = this->clients.binarySearch(temp);
                if (clientP == nullptr) std::cout << "Client " << temp.getClientId() << " was not found in list!" << std::endl;
            }

            else if (index == 1) continue;
            else if (index == 2) break;
            else continue;
        }
    
    }
    
    catch (const std::exception& e)
    {
        std::cerr << "[runClinic] Exception caught: " << e.what() << std::endl;
    }
    
    catch (...)
    {
        std::cerr << "[runClinic] Unknown exception caught" << std::endl;
    }

    stopClinic();
}

void Clinic::stopClinic()
{
    if(clinicThread.joinable()) clinicThread.join();
    if(queueThread.joinable()) queueThread.join();
}

ClientStorage& Clinic::getClients()
{
    return this->clients;
}