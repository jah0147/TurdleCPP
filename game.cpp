//
// Created by jacob_howard on 7/7/2022.
//

#include <cstring>
#include "game.h"
#include "keepScore.h"

void game::guessWord(        int tries,
                     std::string randWord,
                     std::string givenLetters,
                     std::string wordsArray[])
{

    std::string randWord_UPPER = stringChangeCase(randWord, 1);
    std::string randWord_LOWER = stringChangeCase(randWord, 2);
    std::string givenLetters_UPPER = stringChangeCase(givenLetters, 1); //may not work as intended
    bool done = false;

    while ((tries > 0) || (!done)) //If we run out of tries, game-over
    {
        std::string userGuess;
        std::cout << "Guess: ";
        std::cin >> userGuess;

        while (userGuess.length() != randWord.length())
        {
            std::cout << "Please type no more or less than "
                      << randWord.length() << " letters!" << std::endl;
            std::cout << "Please try again..." << std::endl;
            std::cin >> userGuess;
        }
        std::string userGuess_UPPER = stringChangeCase(userGuess, 1);

        //User guessed Correct Word
        if (userGuess_UPPER == randWord_UPPER)
        {
            std::string continueUsrInput;
            std::cout << "That was correct! The word was " << randWord_UPPER << std::endl;
            int GAME_SCORE = score(tries); //stores score for entire game
            std::cout << "Your score is: " << GAME_SCORE << " points!" << std::endl;
            done = true;
        }
        else
        {
            std::string tempString; //temporary string for this case
            for (int i = 0; i < randWord.length(); i++)
            {

                if (randWord_UPPER.find(userGuess_UPPER[i]))
                {
                    tempString = userGuess_UPPER[i];
                    if (randWord_UPPER[i] == userGuess_UPPER[i]) //if user guesses letter in correct place
                    {
                        givenLetters_UPPER[i] = userGuess_UPPER[i];
                    }
                    else if (std::find(correctLetters.begin(), correctLetters.end(), tempString) != correctLetters.end()) //if letter is not already in vector
                    {
                        correctLetters.push_back(tempString);

                    }
                }
                i++;
            }
        }

        tries--; //testing
    }
}

std::string game::stringChangeCase(std::string String, int Case)
{
    switch (Case)
    {
        case UPPER: //upper is int 1
            std::for_each(String.begin(), String.end(), [](char & c) {
                c = ::toupper(c);
            });
            break;

        case LOWER: //lower is int 2
            std::for_each(String.begin(), String.end(), [](char & c) {
                c = ::tolower(c);
            });
        break;
    }
    return String;
}