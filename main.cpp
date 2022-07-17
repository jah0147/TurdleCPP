//global includes
#include <iostream>
//#define TESTING //Deleted all tests; ignore this
//My include files
#include "console.h"
#include "delay.h"
#include "wordGen.h"
#include "game.h"

bool restartGame(bool continueGame,
                 int triesAm,
                 int difficulty,
                 std::string wordsArray[]){
        wordGen wordGen;
        int numOfLinesInList = wordGen.lineNum();
        std::string randWord = wordGen.selectWord(wordsArray, numOfLinesInList);
        std::string randLetters = wordGen.givenLetters(randWord, difficulty);
        game gameRestart;
        continueGame = gameRestart.guessWord(triesAm,
                                             randWord,
                                             randLetters,
                                             wordsArray,
                                             difficulty);
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
delay.DELAY_IN_SECONDS(4); //3 second delay
console::clearConsole(); //should clear console screen

//choose difficulty
console.gameMode(&difficulty, &triesAm);
delay.DELAY_IN_SECONDS(3);
console::clearConsole();

//generate random word
int numOfLinesInList = wordGen.lineNum();
std::string wordsArray[numOfLinesInList];
std::string randWord = wordGen.selectWord(wordsArray, numOfLinesInList);
std::string randLetters = wordGen.givenLetters(randWord, difficulty);

    game game;
    bool continueGame = true;
    
    while (continueGame)
    {
        continueGame = false;
        continueGame = restartGame(continueGame,
                    triesAm,
                    difficulty,
                    wordsArray);
    }

    std::cout <<"\nThank you for playing Turdle!" << std::endl;
    delay.DELAY_IN_SECONDS(1);
return 0;
}

