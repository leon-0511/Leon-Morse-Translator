#include <iostream>
#include <map>
#include <string>
#include <cassert>
#include <limits>

#include "LeonMaps.h"
#include "LeonMorse.h"

int main() {
    std::cout << "0 for Words to Morse, 1 for Morse to Words: ";
    int option;
    std::cin >> option;
    // Clear the newline left in the input buffer by std::cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string input;
    switch(option) {
        case 0:
            std::getline(std::cin, input);
            std::cout << StringToMorse(input) << std::endl;
            break;
        case 1:
            std::getline(std::cin, input);
            std::cout << MorseToString(input) << std::endl;
            break;
        default:
            std::cerr << "Invalid Option";
            return 0;
    }
    return 0;
}
