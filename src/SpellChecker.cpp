
#include "SpellChecker.h"

void SpellChecker::InitDictionary() {
    std::ifstream infile;
    infile.open ("../dictionary.txt");
    while (infile)
    {
        std::string s;
        if (!getline( infile, s )) break;

        std::istringstream ss( s );
        while (ss)
        {
            std::string s;
            if (!getline( ss, s, ',' )) break;
            dictionary_.insert(s);
        }
    }
    infile.close();
}

void SpellChecker::PrintDictionary() {
    for (const auto & word: dictionary_) {
        std::cout << word << "\n";
    }

}

int SpellChecker::GetDistance(const std::string &word_1,size_t s_1, const std::string &word_2,size_t s_2) {

    if (s_1 == 0) return s_2;
    if (s_2 == 0) return  s_1;

    int cost = 0;
    if (word_1.at(s_1 - 1) != word_2.at(s_2 - 1)) { cost = 1;};

    int del = GetDistance(word_1,s_1 - 1,word_2, s_2) + 1;
    int ins = GetDistance(word_1,s_1,word_2,s_2 - 1) + 1;
    int sub = GetDistance(word_1,s_1 - 1,word_2,s_2 - 1) + cost;
    return std::min(del, std::min(ins,sub));

}

void SpellChecker::ReadFile(const std::string &path) {
    std::ifstream infile;
    infile.open (path);
    while (infile)
    {
        std::string s;
        if (!getline( infile, s )) break;

        std::istringstream ss( s );
        while (ss)
        {
            std::string s;
            if (!getline( ss, s, ' ' )) break;
            s.erase(std::remove_if(s.begin(),s.end(),
                                         [](char c)
                                         { return c==','||c=='.'|| c=='!'; }),s.end());
            std::transform(s.begin(),
                           s.end(),
                           s.begin(),
                           [] (unsigned char c) { return std::tolower(c); });
           textWords_.insert(s);
        }
    }
    infile.close();

}
