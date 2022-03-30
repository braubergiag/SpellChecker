#include <iostream>
#include "SpellChecker.h"


int main(){
    std::string path,pathToDictionary = "../dictionary.txt", pathToSourceDir = "../";

    std::cout << "Enter the name of a text file [test file - text.txt]: ";
    std::cin >> path;


    SpellChecker spellChecker;
    spellChecker.InitDictionary(pathToDictionary);
    spellChecker.ReadFile(pathToSourceDir + path);
    spellChecker.Run();

    return 0;
}