//global includes
#include <iostream>
//#define TESTING //Deleted all tests; ignore this
//My include files
#include "console.h"
#include "delay.h"
#include "wordGen.h"
#include "game.h"

void test()
{
    //Testing console class
    console console;
    std::string freeLetter;
    int difficulty, triesAm;

    console.gameMode(&difficulty, &triesAm);
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
    bool continueGame = game.guessWord(triesAm, randWord,randLetters, wordsArray);
    if (continueGame)
    {
        test();
    }
}

bool restartGame(bool continueGame,
                 int triesAm,
                 int difficulty,
                 std::string wordsArray[]){
        wordGen wordGen;
        int numOfLinesInList = wordGen.lineNum();
        std::string randWord = wordGen.selectWord(wordsArray, numOfLinesInList);
        std::string randLetters = wordGen.givenLetters(randWord, difficulty);
        game gameRestart;
        continueGame = gameRestart.guessWord(triesAm, randWord,randLetters, wordsArray);
        return continueGame;
}

int main() {
int difficulty, triesAm;
console console;
delay delay;
wordGen wordGen;

//console
console.printArt();
console.welcome();
delay.DELAY_IN_SECONDS(3); //3 second delay
//console.clearConsole(); //should clear console screen

//choose difficulty
console.gameMode(&difficulty, &triesAm);

//generate random word
int numOfLinesInList = wordGen.lineNum();
std::string wordsArray[numOfLinesInList];
std::string randWord = wordGen.selectWord(wordsArray, numOfLinesInList);
std::string randLetters = wordGen.givenLetters(randWord, difficulty);

//print free letters
//std::cout << "\n Your free letters are\n"<< randLetters << std::endl;
//starting game

    game game;
    bool continueGame = game.guessWord(triesAm, randWord,randLetters, wordsArray);
    while (continueGame)
    {
        continueGame = restartGame(continueGame,
                    triesAm,
                    difficulty,
                    wordsArray);
    }

    std::cout <<"\nThank you for playing Turdle!" << std::endl;
return 0;
}

