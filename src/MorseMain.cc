#include <iostream>
#include <map>
#include <string>
#include <cassert>

#include "LeonMaps.h"

const char kLong = '-';     // 45
const char kShort = '.';    // 46
const char kSpace = '/';    // 47

void ToUpper(char& c) {
    c -= 32;
}

std::string CharToMorse(char c) {
    auto it = AsciiMap.find(c);
    if(it == AsciiMap.end()) {
        std::cerr << "Couldn't find character\n";
        return "";
    }
    return it->second;
        
}

void ReadChar(char& c) {
    char input;
    std::cin >> input;
    if(input >= 'a' && input <= 'z') ToUpper(input);
    if(AsciiMap.find(input) == AsciiMap.end()) return;
    c = input;
}

int main() {
    char letter;
    ReadChar(letter);
    std::cout << CharToMorse(letter) << std::endl;
    // ToUpper for lowercase
    
}
