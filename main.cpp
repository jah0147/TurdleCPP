//global includes
#include <iostream>
#define TESTING //Comment this out when not testing
//My include files
#include "console.h"
#include "delay.h"
#include "wordGen.h"
#include "game.h"

void test()
{
    //Testing console class
    console console;
    std::string freeLetter = "Tests";
    int difficulty, triesAm;

    console.gameMode(freeLetter, &difficulty, &triesAm);
    std::cout << "\nthe difficulty chosen is: " << difficulty << std::endl;
    std::cout << "The triesAmount is: " << triesAm << std::endl;

    //testing wordGen class
    wordGen wordGen;
    int numOfLinesInList = wordGen.lineNum();
    std::string wordsArray[numOfLinesInList];
    std::string randWord = wordGen.selectWord(wordsArray, numOfLinesInList);
    std::cout << "The ArrayList 5 is: " << wordsArray[5] << std::endl;
    std::cout << "The random chosen word is: " << randWord << std::endl;
    std::string randLetters = wordGen.givenLetters(randWord, difficulty);
    std::cout <<"The random letters chosen are: " << randLetters << std::endl;



    //testing game class
    game game;
    game.guessWord(triesAm, randWord,randLetters, wordsArray);
}

int main() {
#ifndef TESTING
console console;
delay delay;
wordGen wordGen;

//console
console.printArt();
console.welcome();
delay.DELAY_IN_SECONDS(3); //3 second delay
//console.clearConsole(); //should clear console screen

//wordGen
std::string randWord = wordGen.selectWord(); //creates a random word
#endif


//Tests
#ifdef TESTING
test();
#endif

return 0;
}

