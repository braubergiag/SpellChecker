//
// Created by marshall on 30.03.2022.
//

#ifndef SPELLCHECKER_SPELLCHECKER_H
#define SPELLCHECKER_SPELLCHECKER_H

#include <set>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
class SpellChecker {
public:
    SpellChecker() {};
    
    void InitDictionary();
    void PrintDictionary();

private:
    std::set<std::string> dictionary_;
};


#endif //SPELLCHECKER_SPELLCHECKER_H