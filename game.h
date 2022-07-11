//
// Created by jacob_howard on 7/7/2022.
//

#ifndef TURDLECPP_GAME_H
#define TURDLECPP_GAME_H

#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

class game{
public:
    void guessWord(int tries,
                   std::string randWord,
                   std::string givenLetters,
                   std::string wordsArray[]);

    bool compairGuess(std::string userGuess, std::string randWord);

    bool contunueGame(bool Continue); //returns a continue game feature

    std::string ArrayToLowerCase(std::string array[]);

    char * stringToChar(std::string String);

private:
    enum CONTINUE_STATE
    {
        YES = true,
        NO = false
    };

    std::vector<std::string> incorrectGuesses;
    std::vector<std::string> incorrectLetters;
};


#endif //TURDLECPP_GAME_H
