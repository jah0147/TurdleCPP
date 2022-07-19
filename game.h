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
//#include <bits/stdc++.h>

#define UPPER_CASE 1
#define LOWER_CASE 2


class game{
public:
    bool guessWord(int tries,
                   std::string randWord,
                   std::string givenLetters,
                   std::string wordsArray[],
                   int difficulty);

    std::string compairGuess(std::string userGuess_UPPER,
                      std::string randWord_UPPER,
                      std::string givenLetters_UPPER);

    void printVectorValues(std::vector<std::string> v);

    std::string stringChangeCase(std::string String, int Case); //turns strings into all lowercase for comparisons

    std::string userInputCase(int &tries,
                              bool &quit);

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

    enum COMMAND_STATE
    {
        isCOMMAND = 1, //checks if trying to use a commmand
        QUIT,
        CHEAT, //cheat command
        DEBUG, //debug command
        WORDLIST, //change wordlist command (this should restart the game with the new wordlist)
        NOTCOMMAND
    };

    std::vector<std::string> correctLetters;
    std::vector<std::string> incorrectGuesses;
    std::vector<std::string> incorrectLetters;
    bool continueGame;
    bool done = false;
    bool quit = false;

    std::string givenLetters_UPPER;
    std::string randWord_UPPER;
    int arrayLength;
    bool didCheat = false; //changes if user uses cheat command
};




#endif //TURDLECPP_GAME_H
