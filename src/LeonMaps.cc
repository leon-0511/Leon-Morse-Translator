#include <map>
#include <iostream>

#include "LeonMaps.h"

const std::map<const char, const std::string> AsciiMap = {
    {' ', "/"     }, {'!', "-.-.--"}, {'\'', ".----."}, {'+', ".-.-."}, 
    {',', "--..--"}, {'-', "-....-"}, {'.',  ".-.-.-"}, {'/', "-..-."}, 

    {'0', "-----"  }, {'1', ".----"}, {'2', "..---" }, {'3', "...--" }, 
    {'4', "....-"  }, {'5', "....."}, {'6', "-...." }, {'7', "--..." }, 
    {'8', "---.."  }, {'9', "----."},
    
    {':', "---..."}, {';', "-.-.-."}, {'=', "-...-"}, {'?', "..--.."}, 

    {'A', ".-"  }, {'B', "-..."}, {'C', "-.-."}, {'D', "-.." },
    {'E', "."   }, {'F', "..-."}, {'G', "--." }, {'H', "...."}, 
    {'I', ".."  }, {'J', ".---"}, {'K', "-.-" }, {'L', ".-.."},
    {'M', "--"  }, {'N', "-."  }, {'O', "---" }, {'P', ".--."}, 
    {'Q', "--.-"}, {'R', ".-." }, {'S', "-"   }, {'T', "..." },
    {'U', "..-" }, {'V', "...-"}, {'W', ".--" }, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, 
};

std::map<std::string, char> MorseMap;

void BuildMorseMap(std::map<std::string, char>& MorseMap) {
    for(const auto& pair : AsciiMap) {
        MorseMap[pair.second] = pair.first;
    }
}

void PrintMap(std::map<std::string, char> map) {
    for(const auto& pair : map) {
        std::cout << "Morse: "<< pair.first << "\tChar: " << pair.second << '\n';
    }
}

