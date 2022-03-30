
#include "SpellChecker.h"

void SpellChecker::InitDictionary(const std::string &path) {
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
           inputText_.push_back(s);
        }
    }
    infile.close();

}

void SpellChecker::Run() {

    for (auto & word : inputText_) {
        if (dictionary_.count(word) == 0) {
            std::vector<std::string> possibleWords;
            for (const auto &dictWord : dictionary_) {
                if (GetDistance(word, word.size(), dictWord, dictWord.size()) == 1) {
                    possibleWords.push_back(dictWord);

                }

            }
            std::string command;
            int commandNumber = 0;
                std::cout << "Current word: " + word + "\n" + GenerateHelp(possibleWords.size() > 0);
                commandNumber = InputIntNumber({"Enter your choice (option number): "},
                                               {"Enter your choice as a whole number: "});
                RequestType requestType;
                if (CheckRequestType(commandNumber)) {
                    requestType = static_cast<RequestType>(commandNumber);
                } else {
                    std::cout << "Incorrect command \n";
                    continue;
                }

                switch (requestType) {
                    case RequestType::KEEP:
                        editedText_.push_back(word);
                        continue;
                    case RequestType::ADD:
                        dictionary_.insert(word);
                        editedText_.push_back(word);
                        continue;
                    case RequestType::REPLACE: {
                        if (possibleWords.size() == 0) {
                            std::cout << "No possible replacements\n";
                            continue;
                        }
                        Replace(possibleWords);

                    }
                    case RequestType::STOP: {
                        return;
                    }
                    default:
                        break;
                }


        } else {
            editedText_.push_back(word);
        }
    }
    WriteToFile("../out.txt");
}
bool SpellChecker::CheckRequestType(int commandNumber) const {
    if (commandNumber < 0 || commandNumber >= static_cast<int>(RequestType::REQUEST_COUNT)) {
        return false;
    }
    return true;
}
int SpellChecker::InputIntNumber(const std::string &hint, const std::string &errorHint) const {
    std::string input;
    bool isOk = false;
    int number;
    std::cout << hint;
    std::cin >> input;
    while (!isOk){
        try {
            number = std::stoi(input);
            isOk = true;
        } catch (std::invalid_argument const& ex) {
            std::cout << errorHint;
            std::cin >> input;
        }
    }
    return number;
}
std::string SpellChecker::GenerateHelp(bool replaceOption) const {
    std::string help = {};
    help += "1. Leave the word unchanged \n";
    help += "2. Add word to dictionary AS IS \n";
    if (replaceOption) {
        help += "3. Show possibles replacements \n";
    }
    help += "0. Quit \n";

    return help;
}

void SpellChecker::WriteToFile(const std::string &path) {
    std::ofstream out (path , std::ios::out);
    if (out.is_open())
    {
        for (const auto & word : editedText_) {
            out << word << " ";
        }
        out.close();
    }

}

void SpellChecker::SetInputPath(const std::string &path) {
    inputPath_ = path;

}

SpellChecker::SpellChecker() {

}

void SpellChecker::Replace(const std::vector<std::string> possibleWords) {
    int counter = 0;
    for (const auto& replWord : possibleWords) {
        std:: cout << ++counter  << ". " + replWord << "\n";
    }
    int choiceWord = InputIntNumber("Enter number of word you want to take: ", "Enter the thole number: ");
    editedText_.push_back(possibleWords.at(choiceWord - 1));
}

