#include <iostream>
#include "SpellChecker.h"


int main(){
    SpellChecker spellChecker{};
    spellChecker.InitDictionary();
    spellChecker.PrintDictionary();

    return 0;
}