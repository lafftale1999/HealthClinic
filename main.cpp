#include "include/clientStorage.h"
#include "include/clinic.h"
#include "include/queue.h"
#include <iostream>

int main()
{
    int amount = 100000;
    Clinic clinic(amount, CREATE);

    clinic.openClinic();
    
    return 0;
}

