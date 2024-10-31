#include <iostream>
#include <map>
#include <string>
#include <cassert>
#include <limits>

#include "LeonMaps.h"

char ToUpper(char c) {
    return (c - 32);
}

bool IsLower(char c ) {
    return (c >= 'a' && c <= 'z');
}

void PrintMap(std::map<std::string, char> map) {
    for(const auto& pair : map) {
        std::cout << "Morse: "<< pair.first << "\tChar: " << pair.second << '\n';
    }
}

char MorseToChar(const std::string& morse, bool& valid) {
    auto it = MorseMap.find(morse);
    // std::cout << "It->first: " << it->first << " It->second: " << it->second << '\n'; 
    if(it == MorseMap.end()) {
        std::cerr << "Invalid Morse code\n";
        valid = false;
        return '\0';
    }
    return it->second;
}

std::string MorseToString(const std::string& morse) {
    BuildMorseMap(MorseMap);
    // PrintMap(MorseMap);
    std::string str{""};
    std::string word{""};
    bool valid = true;
    for(int i{0}; i <= static_cast<int>(morse.length()); i++) {
        // If end of word, turn morse code into char, then add to string
        if(morse[i] == ' ' || morse[i] == '\0') {
            char c = MorseToChar(word, valid);
            // If not valid morse code, return error
            if(!valid) return "INVALID INPUT\n";
            str.push_back(c);
            word.clear();
            continue;
        }
        // Add character to word
        word += morse[i];
    }
    return str;
}

std::string CharToMorse(char c, bool& valid) {
    auto it = AsciiMap.find(c);
    if(it == AsciiMap.end()) {
        std::cerr << "Couldn't find character\n";
        valid = false;
        return "";
    }
    return it->second;
}

std::string StringToMorse(const std::string& str) {
    std::string morse{""};
    bool valid = true;
    for(int i{0}; i < static_cast<int>(str.length()); i++) {
        char c = str[i];
        if(IsLower(c)) {
            c = ToUpper(c);
        }
        morse += CharToMorse(c, valid) + ' ';
        if(!valid) return "INVALID INPUT\n";
    }
    return morse;
}

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
