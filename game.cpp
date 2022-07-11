//
// Created by jacob_howard on 7/7/2022.
//

#include <cstring>
#include "game.h"

void game::guessWord(int tries,
                     std::string randWord,
                     std::string givenLetters,
                     std::string wordsArray[])
{
    char cRandWord = *game::stringToChar(randWord);
    std::cout << cRandWord; //test

    std::cout << "The game has picked a " << randWord.size() << " letter word." << std::endl;
    while (tries > 0) //If we run out of tries, game-over
    {

    }
}

char * stringToChar(std::string String)
{
    int n = String.length();

    // declaring character array
    char char_array[n + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, String.c_str());

    return char_array;
}

//std::string ArrayToLowerCase(std::string array)
//{
//    for (std::string & s : array)
//        std::transform(s.begin(), s.end(), s.begin(),
//                       [](unsigned char c) { return std::tolower(c); });
//}