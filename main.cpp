#include "include/clinic.h"
#include <fstream>
#include <iomanip> // For std::setw and std::setfill
#include <algorithm>
#include "binarySearch.h"

int main()
{
    
    Clinic clinic;

    const int AntalAccounts = 100;

    // std::ifstream MyFile("randomNumbers.txt");
    std::ifstream MyFile("sorted.txt");
    if (!MyFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;  // Return an error if the file cannot be opened
    }
    for (int i = 0; i < AntalAccounts; i++) {
        std::string line;
        if (std::getline(MyFile, line)) {
            clinic.getClients().addClient(Client(line));
        } else {
            std::cerr << "Error reading line " << i << " from the file." << std::endl;
        }
    }   
    MyFile.close();

    std::sort(clinic.getClients().getList().begin(), clinic.getClients().getList().end()); 

    // std::ofstream sorted("sorted.txt");
    // for (Client client : clinic.getClients().getList()) {
    //     sorted << client.getClientId() << std::endl;
    // }
    // sorted.close();

    std::string target = "190384";

     Client* result = binarySearch(clinic.getClients().getList(), target);
    if (result != nullptr) {
        std::cout << "Found client with ID: " << result->getClientId() << std::endl;        
        result->setClientId("111111");
        std::cout << "Found client replaced with ID: " << result->getClientId() << std::endl;
    } else {
        std::cout << "Client not found" << std::endl;
    }

     std::ofstream sorted("sorted.txt");
    for (Client client : clinic.getClients().getList()) {
        sorted << client.getClientId() << std::endl;
    }
    sorted.close();

return 0;
}