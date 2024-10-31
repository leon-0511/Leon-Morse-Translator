#if !defined(LEONMORSE_H)
#define LEONMORSE_H

bool IsLower(char c);
char ToUpper(char c);
char MorseToChar(const std::string& morse, bool& valid);
std::string MorseToString(const std::string& morse);
std::string CharToMorse(char c, bool& valid);
std::string StringToMorse(const std::string& str);

#endif // LEONMORSE_H