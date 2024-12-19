#include "include/clinic.h"
#include <fstream>
#include <iomanip> // For std::setw and std::setfill
#include <algorithm>
#include "binarySearch.h"

int main()
{
    
    Clinic clinic;

    const int AntalAccounts = 100;

    std::ifstream MyFile("randomNumbers.txt");if (!MyFile.is_open()) {
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

    std::ofstream sorted("sorted.txt");
    for (Client client : clinic.getClients().getList()) {
        sorted << client.getClientId() << std::endl;
    }
    
    for(int i = 0; i < AntalAccounts; i++){
        std::cout << clinic.getClients().getClient(i).getClientId() << std::endl;
    }

    std::string target = "915384";

     Client* result = binarySearch(&clinic, clinic.getClients().getList().size(), target);
    if (result != nullptr) {
        std::cout << "Found client with ID: " << result->getClientId() << std::endl;
    } else {
        std::cout << "Client not found" << std::endl;
    }

// std::ifstream randomFile("randomNumbers.txt");
// std::string line;
// std::vector<std::string> IDs;
//     while (std::getline(randomFile, line)) { 
//         // std::cout << line << std::endl;
//         IDs.push_back(line);
//     }
//     randomFile.close();
//     for(std::string id : IDs){
//         std::cout << id << std::endl;
//     }

//     std::sort(IDs.begin(), IDs.end());

//     std::ofstream sorted("sorted.txt");
//     for (std::string id : IDs) {
        
//         sorted << id << std::endl;
//     }
//         MyFile.close();

    // std::string target = "000050";
    // int *result = binarySearch(IDs, IDs.size(), target);
    // std::cout << "Found at index: " << result << std::endl;

return 0;
}