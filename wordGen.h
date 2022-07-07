//
// Created by jacob_howard on 7/7/2022.
//

#ifndef TURDLECPP_WORDGEN_H
#define TURDLECPP_WORDGEN_H

//#include <wsman.h>
#include <vector>
#include "iostream"

class wordGen {
public:
    //wordGen();
    std::string selectWord();
    int lineNum();

private:
    //std::vector<std::string> wordsArray[NULL];
    std::string filename = "textFiles/wordBank/wordle.txt";
};


#endif //TURDLECPP_WORDGEN_H
