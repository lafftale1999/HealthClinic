#include "binarySearch.h"
#include "include/clinic.h"

Client *binarySearch(std::vector<Client>& clientlist,  const std::string target) {
    int start = 0;
    int end = clientlist.size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        // Access the vector of clients
        // Client& midClient = clientlist.getClients().getList().at(mid);
        Client& midClient = clientlist.at(mid);

        // Compare the client ID with the target
        if (midClient.getClientId() == target) {
            
            return &midClient;
        } 
        else if (midClient.getClientId() < target) {
            start = mid + 1;
        } 
        else {
            end = mid - 1;
        }
    }

    return nullptr;  
}