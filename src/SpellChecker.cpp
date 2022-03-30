
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
}

void SpellChecker::PrintDictionary() {
    for (const auto & word: dictionary_) {
        std::cout << word << "\n";
    }

}
