#include <map>
#include <string>

#ifndef LEONMAPS_H
#define LEONMAPS_H

extern const std::map<const char, const std::string> AsciiMap;

extern std::map<std::string, char> MorseMap;

void BuildMorseMap(std::map<std::string, char>& MorseMap);




#endif // LEONMAPS_H