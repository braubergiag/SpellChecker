#include <iostream>
#include "SpellChecker.h"


int main(){
    SpellChecker spellChecker{};
    spellChecker.InitDictionary();
    spellChecker.PrintDictionary();

    std::string word_1;
    std::string word_2;
    std::cin >> word_1;
    std::cin >> word_2;

    std::cout << spellChecker.GetDistance(word_1,word_1.size(),word_2,word_2.size());

    return 0;
}