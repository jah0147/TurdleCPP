//
// Created by jacob_howard on 7/7/2022.
//

#ifndef TURDLECPP_WORDGEN_H
#define TURDLECPP_WORDGEN_H

//#include <wsman.h>
#include <vector>
#include "iostream"
#include "string"

class wordGen {
public:
    //wordGen();
    std::string selectWord();
    int lineNum();
    std::string givenLetters(std::string randWord, int difficulty);
    std::string arrayToString(std::string* array, int size);

private:
    //std::vector<std::string> wordsArray[NULL];
    std::string filename = "textFiles/wordBank/wordle.txt";
    enum DIFFICULTY_STATE
    {
        EASY = 1,
        MEDIUM = 2,
        HARD = 3
    };
};


#endif //TURDLECPP_WORDGEN_H
