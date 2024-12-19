#include "../include/clinic.h"

Clinic::Clinic()
{

}


ClientStorage& Clinic::getClients()
{
    return this->clients;
}