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

enum class RequestType {
    STOP = 0,
    KEEP = 1,
    ADD = 2,
    REPLACE = 3,
    REQUEST_COUNT = 4

};

class SpellChecker {
public:
    SpellChecker();

    int GetDistance(const std::string &word_1,size_t s_1, const std::string &word_2,size_t s_2);
    std::string GenerateHelp(bool replaceOption) const;
    void ReadFile(const std::string & path);
    void WriteToFile(const std::string & path);
    void InitDictionary(const std::string &path);
    void PrintDictionary();
    void SetInputPath(const std::string & path);
    void SetDictionaryPath(const std::string & path);
    bool CheckRequestType(int commandNumber) const;
    int InputIntNumber(const std::string &hint = {}, const std::string &errorHint = {}) const;
    void Replace(const std::vector<std::string> possibleWords);
    void Run();

private:
    std::string inputPath_;
    std::string outputPath_;
    std::string dictionaryPath_;
    std::set<std::string> dictionary_;
    std::vector<std::string> inputText_;
    std::vector<std::string> editedText_;
};


#endif //SPELLCHECKER_SPELLCHECKER_H
