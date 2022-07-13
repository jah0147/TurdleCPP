//
// Created by jacob_howard on 7/7/2022.
//

#ifndef TURDLECPP_GAME_H
#define TURDLECPP_GAME_H

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>

#define UPPER_CASE 1
#define LOWER_CASE 2

class game{
public:
    void guessWord(int tries,
                   std::string randWord,
                   std::string givenLetters,
                   std::string wordsArray[]);

    std::string compairGuess(std::string userGuess_UPPER,
                      std::string randWord_UPPER,
                      std::string givenLetters_UPPER);

    void printVectorValues(const std::vector<std::string>& v);

    bool contunueGame(bool Continue); //returns a continue game feature

    std::string stringChangeCase(std::string String, int Case); //turns strings into all lowercase for comparisons

private:
    enum CONTINUE_STATE
    {
        YES = true,
        NO = false
    };
    enum String_Case
    {
        UPPER = 1,
        LOWER = 2
    };

    std::vector<std::string> correctLetters;
    std::vector<std::string> incorrectGuesses;
    std::vector<std::string> incorrectLetters;
};




#endif //TURDLECPP_GAME_H
