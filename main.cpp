#include "include/clientStorage.h"
#include "include/clinic.h"
#include "include/queue.h"
#include <iostream>

int main()
{
    try {
        int amount = 10000000;
        Clinic clinic(amount, CREATE);

        clinic.openClinic();
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}

