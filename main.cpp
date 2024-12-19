#include "include/clinic.h"
#include "binarySearch.h"
#include <fstream>
#include <iomanip> // For std::setw and std::setfill
#include <algorithm>

int main()
{
    
    Clinic clinic;
    std::string line;
    int addedclientcount = 0;

    // Open the randomNumbers.txt file and load the data into the vector
    std::ifstream orginalfile("randomNumbers.txt");
    if (!orginalfile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
    }
    // Read each line until EOF and add clients
    while (std::getline(orginalfile, line)) {
        try {
            if (line.empty()) {
                std::cerr << "Warning: Empty line encountered at line " << addedclientcount + 1 << "." << std::endl;
                continue;  // Skip empty lines
            }
            clinic.getClients().addClient(Client(line));
            addedclientcount++;
        } 
        catch (const std::exception& e) {
            std::cerr << "Error processing line " << addedclientcount + 1 << ": " << e.what() << std::endl;
        }
    }
    orginalfile.close();
    // std::cout << "Successfully processed " << addedclientcount << " clients from the file." << std::endl;
// sorting the clients
    std::sort(clinic.getClients().getList().begin(), clinic.getClients().getList().end()); 

    std::string target = "415826";
    Client* result = binarySearch(clinic.getClients().getList(), target);
    if (result != nullptr) {
        std::cout << "Found client with ID: " << result->getClientId() << std::endl;        
        // result->setClientId("111111");
        // std::cout << "Found client replaced with ID: " << result->getClientId() << std::endl;
    } else {
        std::cout << "Client not found" << std::endl;
    }
    
    // std::sort(clinic.getClients().getList().begin(), clinic.getClients().getList().end()); 

    // change the client ID to 111111 in the sorted.txt file
     std::ofstream sorted("sorted.txt");
    for (Client client : clinic.getClients().getList()) {
        sorted << client.getClientId() << std::endl;
    }
    sorted.close();

return 0;
}