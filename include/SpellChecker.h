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
#include <algorithm>
class SpellChecker {
public:
    SpellChecker() {};

    int GetDistance(const std::string &word_1,size_t s_1, const std::string &word_2,size_t s_2);
    void ReadFile(const std::string & path);
    void InitDictionary();
    void PrintDictionary();

private:
    std::set<std::string> dictionary_;
    std::set<std::string> textWords_;
};


#endif //SPELLCHECKER_SPELLCHECKER_H
