#include <iostream>
#include <map>

#include "LeonMaps.h"

char ToUpper(char c) {
    return (c - 32);
}

bool IsLower(char c ) {
    return (c >= 'a' && c <= 'z');
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