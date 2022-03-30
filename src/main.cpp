#include <iostream>
#include "SpellChecker.h"


int main(){
    std::string path = "../text.txt";
    SpellChecker spellChecker{};
    spellChecker.InitDictionary();
    spellChecker.PrintDictionary();

    spellChecker.ReadFile(path);

    return 0;
}