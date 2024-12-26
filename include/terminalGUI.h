#ifndef TERMINAL_GUI_H
#define TERMINAL_GUI_H

#include <istream>
#include <vector>

class TerminalGUI
{
public:
    TerminalGUI();
    int printMenu(std::string headline, std::string message, std::vector<std::string> options);
    void clearScreen();

};

#endif