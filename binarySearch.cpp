#include "binarySearch.h"
#include "include/clinic.h"

Client *binarySearch(Clinic* clientlist, int size, const std::string& target) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        // Access the vector of clients
        Client& midClient = clientlist->getClients().getList().at(mid);

        // Compare the client ID with the target
        if (midClient.getClientId() == target) {
            return &clientlist->getClients().getList().at(mid);  // Return a pointer to the matching Client
        } 
        else if (midClient.getClientId() < target) {
            start = mid + 1;
        } 
        else {
            end = mid - 1;
        }
    }

    return nullptr;  // Return nullptr if the target is not found
}
