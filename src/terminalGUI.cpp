#include "../include/terminalGUI.h"
#include <stdlib.h>
#include <iostream>

TerminalGUI::TerminalGUI(){}

int TerminalGUI::printMenu(std::string headline, std::string message, std::vector<std::string> options)
{
    clearScreen();

    std::cout << headline << std::endl;
    std::cout << message << std:: endl;

    for(size_t i = 0; i < options.size(); i++)
    {
        std::cout << i << ". " << options.at(i) << std::endl;
    }

    size_t userChoice = -1;

    while(1)
    {
        if(!(std::cin >> userChoice) || (userChoice < 0 || userChoice > options.size()))
        {
            std::cout << "Please enter an integer between 0 and " << options.size() << std::endl;
            continue;
        }

        return userChoice;
    }
}

void TerminalGUI::clearScreen()
{
    system("cls");
}