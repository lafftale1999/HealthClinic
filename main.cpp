#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <fstream> //file input/output.
#include "clientStorage.h"
#include "clinic.h"


int main(){
    std::vector<int> numbers;
    Clinic clinic;

    const int NUM_CLIENTS = 10;
    for(int i = 1; i <= NUM_CLIENTS; i++){ // created all numbers in order. 
        numbers.push_back(i);
    }

    srand(time(0));// seed the random number generator.
    //Shuffle the numbers.
    for(int i = numbers.size() - 1; i > 0; i--){
        int j = rand() % (i + 1);
        //Shuffle
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }


    //Create clients using the random numbers.
    for(int num : numbers){
        clinic.addClient(std::to_string(num));
    }

    
    //Print all client IDs
    ClientStorage& storage = clinic.getClients();//get storage from clinic.
    std::cout << "Current run; \n";
    std::cout << "==========================\n";
    for(int i = 0; i < 10; i++){
        Client& client= storage.getClient(i); // get client from storage
        std::cout << "Client " << (i + 1) << ": " << client.getClientId() << std::endl;
    }
    std::cout << "===========================\n\n";

    //Save to file:
    std::ofstream fout;
    fout.open("clients.txt", std::ios::app);//append mode: for every run, shows in file.
    if(fout.is_open()){
        fout << "\n=====================\n";
        for(int i = 0; i < 10; i++){
            Client& client = storage.getClient(i);
            fout << "Client " << (i + 1) << ": " << client.getClientId() << std::endl;
        }
        fout << "\n=====================\n\n";
        fout.close();
        std::cout << "Clients saved to file successfully!\n\n";
    }

    //Read from file 
    std::ifstream fin("clients.txt");
    if(fin.is_open()) {
        std::string line;
        std::cout << "Reading from file:\n";
        while(getline(fin,line)){
            std::cout << line << std::endl;
        }
        fin.close();
    }

    return 0; 

}