#include <iostream>
#include "SpellChecker.h"


int main(){
    std::string path,pathToDictionary = "dictionary.txt";

    std::cout << "Enter the name of a text file [test file - t.txt]: ";
    std::cin >> path;


    SpellChecker spellChecker;
    spellChecker.InitDictionary(pathToDictionary);
    spellChecker.ReadFile(path);
    spellChecker.Run();

    return 0;
}