//
// Created by jacob_howard on 7/7/2022.
//

#include "game.h"
#include "keepScore.h"
#include "console.h"
#include "delay.h"
#include "wordGen.h"

bool game::guessWord(int tries,
                     std::string randWord,
                     std::string givenLetters,
                     std::string wordsArray[],
                     int difficulty)
{
    delay delay;
    wordGen wordGen;
    console console; //init console

    arrayLength = wordGen.lineNum();
    std::string wordsArray_UPPER[arrayLength];
    randWord_UPPER = stringChangeCase(randWord, UPPER);
    givenLetters_UPPER = stringChangeCase(givenLetters, UPPER); //may not work as intended
    //capitalizing words array
    for (int i = 0; i < arrayLength; i++) {
        wordsArray_UPPER[i] = stringChangeCase(wordsArray[i], UPPER);
    }

    std::string userGuess;

    //starting game
    while ((tries > 0) & (!done) & (!quit)) //If we run out of tries, game-over
    {
        std::string userGuess_UPPER = stringChangeCase(userGuess, UPPER_CASE);

            //User guessed Correct Word
            if (userGuess_UPPER == randWord_UPPER) {

                console::clearConsole();
                std::string continueUsrInput;
                std::cout << "---------------------------------------***CORRECT***---------------------------------------" << std::endl;
                std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "                                     The word was " << randWord_UPPER << std::endl;
                std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "----------------------------------------***SCORE***----------------------------------------" << std::endl;

                GAME_SCORE = score(tries, false); //stores score for entire game

                if (didCheat) //checks if user cheated
                {
                    GAME_SCORE = score(0, true); //resets game score to zero if user cheated
                }

                std::cout << "                                   Your score is: " << GAME_SCORE << " points!" << std::endl;
                std::cout << "-------------------------------------------------------------------------------------------" << std::endl;

                if (didCheat) { //If the user used the cheat command
                    std::cout << "\n-------------------------------------------CHEATER-------------------------------------" << std::endl;
                    std::cout << "                          You did cheat though... Not very impressive." << std::endl;
                    std::cout << "                           I went ahead and reset your score to zero." << std::endl;
                    std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
                }

                done = true;
                delay.DELAY_IN_SECONDS(2);
            } else {
                console::clearConsole();
                if (realWord) {
                    givenLetters_UPPER = compairGuess(userGuess_UPPER,
                                                      randWord_UPPER,
                                                      givenLetters_UPPER);
                }


                std::cout
                        << "--------------------------------------------------------------------------------------------"
                        << std::endl;
                //Prints correct letters guessed
                std::cout << "Incorrect words guessed: [";
                printVectorValues(incorrectGuesses);
                std::cout << "]" << std::endl;
                std::cout
                        << "--------------------------------------------------------------------------------------------"
                        << std::endl;

                std::cout << std::endl;
                std::cout << "                                            ";
                for (int i = 0; i < givenLetters_UPPER.size(); i++) {
                    std::cout << givenLetters_UPPER[i] << " ";
                }
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout
                        << "--------------------------------------------------------------------------------------------"
                        << std::endl;
                //Prints correct letters guessed
                std::cout << "Correct letters guessed in wrong location: [";
                printVectorValues(correctLetters);
                std::cout << "]" << std::endl;

                std::cout << "Incorrect letters guessed: [";
                printVectorValues(incorrectLetters);
                std::cout << "]" << std::endl;

                std::cout
                        << "--------------------------------------------------------------------------------------------"
                        << std::endl;
                std::cout << "                                        Tries left: " << tries << std::endl;
                std::cout
                        << "--------------------------------------------------------------------------------------------"
                        << std::endl;
                std::cout << std::endl;

                if (!realWord)
                {
                    if (difficulty == 1) {
                        std::cout << "Please type no more or less than "
                                  << randWord_UPPER.length() << " letters!" << std::endl;
                        std::cout << "Please try again..." << std::endl;
                    }
                    else {
                        std::cout << "That is not a word in the word bank!" << std::endl;
                        std::cout << "Please try again..." << std::endl;
                    }
                }

                userGuess = userInputCase(tries, quit); //Checks if user inputs a command or just a word

                while ((userGuess[0]== '/') & (!quit)) //if user input command. ask for guess again
                {
                    userGuess = userInputCase(tries, quit); //Checks if user inputs a command or just a word
                }
                if (!quit) {
                    if (difficulty == 1) { //if easy mode
                        checkIfWord(difficulty, userGuess, wordsArray_UPPER);
                        if (realWord)
                        {
                            userGuess = checkIfWord(difficulty, userGuess, wordsArray_UPPER);
                        }
                    }
                    else { //if medium or hard mode
                        // Checks if word exists in wordlist
                        checkIfWord(difficulty, userGuess, wordsArray_UPPER);
                        if (realWord)
                        {
                            userGuess = checkIfWord(difficulty, userGuess, wordsArray_UPPER);
                        }
                    }
            }
            if ((difficulty != 1) & (realWord)) {
                tries--;
            }
            else if ((difficulty == 1) && (userGuess.length() == randWord.length()))
            {
                tries --;
            }
        }
    }

    if (!quit) {
        if (done) {
            std::cout << "Would you like to continue? (Y/N): ";
            std::string userInContinue;
            std::cin >> userInContinue;
            userInContinue = stringChangeCase(userInContinue, UPPER_CASE);
            if (userInContinue == "Y" || userInContinue == "YES") {
                continueGame = true;
            } else {
                continueGame = false;
            }
        } else {
            std::string gameOverInput;
            console::clearConsole();

            std::cout
                    << "------------------------------------------GAME OVER----------------------------------------"
                    << std::endl;
            std::cout << "                                  You have ran out of tries..." << std::endl;
            std::cout
                    << "--------------------------------------------------------------------------------------------"
                    << std::endl;
            std::cout << "                                      The word was " << randWord_UPPER << std::endl;
            std::cout
                    << "--------------------------------------------------------------------------------------------"
                    << std::endl;
            std::cout
                    << "--------------------------------------------SCORE--------------------------------------------"
                    << std::endl;
            std::cout << "                                    Your score was " << GAME_SCORE << " points!" << std::endl;
            std::cout
                    << "--------------------------------------------------------------------------------------------"
                    << std::endl;
            delay.DELAY_IN_SECONDS(1);
            std::cout << "                              \nWould you like to play again? (Y/N)" << std::endl;
            std::cout << "Input: ";
            std::cin >> gameOverInput;
            gameOverInput = stringChangeCase(gameOverInput, UPPER_CASE);
            if (gameOverInput == "Y" || gameOverInput == "YES")
            {
                GAME_SCORE = score(0, true);
                continueGame = true;
            } else {
                continueGame = false;
            }
        }
    }
    else {
        continueGame = false;
    }
    return continueGame; //used in main function
}

std::string game::userInputCase(int &tries,
                                bool &quit)
{
    std::string wordlist;
    std::cout << "\nPlease enter your guess.\n" << std::endl;
    std::string usrInput = "";
    std::cout << "Input: ";
    std::cin >> usrInput;
    usrInput = stringChangeCase(usrInput, LOWER_CASE); //changing input to lower case (might give errors with commands
    int checkIfCommand;
    int usrCommand;
    //cheatMenu inputs
    std::string cheatMenuInput;
    int cheatMenuInputInt;

    if (usrInput[0] == '/')
    {
        checkIfCommand = isCOMMAND;
        if (usrInput == "/quit") {usrCommand = QUIT;}
        else if (usrInput == "/cheat") {usrCommand = CHEAT;}
        else if (usrInput == "/debug") {usrCommand = DEBUG;}
        else if (usrInput == "/wordlist") {usrCommand = WORDLIST;}
        else if (usrInput == "/help") {usrCommand = HELP;}
        else {usrCommand = HELP;} //if user inputs a non-existent command
    }
    else {
        checkIfCommand = 0; //not command, should be a user guess
    }


    switch (checkIfCommand)
    {
        case isCOMMAND: //isCommand
            console::clearConsole(); //clears console

            switch (usrCommand) {
                case QUIT: //user chose to quit game
                    delay delay;
                    std::cout << "You chose to quit the game..." << std::endl;
                    std::cout << "The word was " << randWord_UPPER << std::endl;
                    delay.DELAY_IN_SECONDS(3); //delay before quit so user can see word before game end
                    quit = true;
                    break;
                case CHEAT:
                    if (!didCheat)
                    {
                        didCheat = true;
                        std::cout << "\n--------------------------CHEAT MENU--------------------------" << std::endl;
                        std::cout << "  Would you like an extra letter in the word or more tries?" << std::endl;
                        std::cout << "--------------------------------------------------------------" << std::endl;
                        std::cout << "[1] Add Extra Letter" << std::endl;
                        std::cout << "[2] Add Attempts" << std::endl;
                        std::cout << "--------------------------------------------------------------" << std::endl;
                        //User input
                        std::cout << "\nInput: ";
                        std::cin >> cheatMenuInput;
                        //Decides the cheat
                        if (cheatMenuInput == "1") { //adds a letter to the word
                            int i = 0;
                            while (givenLetters_UPPER[i] != '_') {
                                i++;
                            }
                            console::clearConsole();
                            givenLetters_UPPER[i] = randWord_UPPER[i];
                            std::cout << "Your given letters are: " << givenLetters_UPPER << std::endl;
                        } else if (cheatMenuInput == "2") { //adds users tries
                            console::clearConsole();
                            std::cout << "How many ties would you like to add?" << std::endl;
                            std::cout << "Input: ";
                            std::cin >> cheatMenuInputInt;

                            tries += cheatMenuInputInt;
                            console::clearConsole();
                            std::cout << "You now have " << tries << " tries remaining" << std::endl;
                            delay.DELAY_IN_SECONDS(2);
                            console::clearConsole();
                        } else { //If user inputs invalid input, we just exit the menu
                            std::cout << "Not a valid input..." << std::endl;
                            std::cout << "Exiting Cheat Menu" << std::endl;
                            delay.DELAY_IN_SECONDS(1);
                            console::clearConsole();
                        }

                    }//if (!didCheat)
                    else
                    {
                        std::cout << "You may only use the cheat command once per game." << std::endl;
                    }
                    break;
                case DEBUG:
                    std::cout << "\n--------------------------DEBUG MODE--------------------------" << std::endl;
                    std::cout << "The random word is: " << randWord_UPPER << std::endl;
                    std::cout << "--------------------------------------------------------------" << std::endl;
                    delay.DELAY_IN_SECONDS(2);
                    console::clearConsole();
                    break;
                    //wordlist not functioning yet
                case WORDLIST: //Changing the wordlist should somehow restart the game with new wordlist
                    std::cout << "What would you like to change the wordlist to?" << std::endl;
                    std::cout << "Input: ";
                    std::cin >> wordlist;
                    break;
                case HELP:
                    std::cout << "\n--------------------------HELP MENU--------------------------" << std::endl;
                    std::cout << "--------------------------------------------------------------" << std::endl;
                    std::cout << "                          List of Commands" << std::endl;
                    std::cout <<"\n"; //just adding space
                    std::cout << "           /quit       -Quits the game" << std::endl;
                    std::cout << "           /cheat      -Opens the cheat menu" << std::endl;
                    std::cout << "           /wordlist   -Lets you change the current wordlist" <<std::endl;
                    std::cout << "--------------------------------------------------------------" << std::endl;
                    break;
                case NOTCOMMAND:
                    std::cout << "That is not a valid command..." << std::endl;
                    break;
            }
            break;
        default:
            return usrInput; //only return user input if they do not input a command
    }
    return usrInput; //only return user input if they do not input a command
}

/*
 * Function: checkIfWord
 * Description: Takes the user input and compairs it to the word list
 * to see if the word exists. Only does this for medium or hard mode.
 */

std::string game::checkIfWord(int difficulty,
                  std::string userGuess,
                  std::string wordsArray_UPPER[])
{
    if (difficulty == 1)
    {
        realWord = false;
        std::string userGuess_UPPER = stringChangeCase(userGuess, UPPER_CASE);
        if (userGuess_UPPER.size() == randWord_UPPER.size())
        {
            realWord = true;
        }
    }
    else if (difficulty != 1) //if the difficulty is not set to easy (this is a mess)
    {
        realWord = false;

        std::string userGuess_UPPER = stringChangeCase(userGuess, UPPER_CASE);
        for (int i = 0; i < arrayLength; i++) {
            if (userGuess_UPPER == wordsArray_UPPER[i]) //checks to see if word exists in wordbank
            {
                realWord = true;
            }
        }
    }
    return userGuess;
}

/*
 * Function: compairGuess
 * Description: Takes users guess and correctly
 *  distributes letters and words to correct vector storage.
 */
std::string game::compairGuess(std::string userGuess_UPPER,
                        std::string randWord_UPPER,
                        std::string givenLetters_UPPER)
{
    std::string tempString; //temporary string for this case
    for (int i = 0; i < randWord_UPPER.length(); i++)
    {
        tempString = userGuess_UPPER[i];
        if (randWord_UPPER.find(userGuess_UPPER[i]) != std::string::npos)  //If correctl letters exist in guess
        {
            if (randWord_UPPER[i] == userGuess_UPPER[i]) //if user guesses letter in correct place
            {
                givenLetters_UPPER[i] = userGuess_UPPER[i];
            } else
            {
                if (std::find(correctLetters.begin(), correctLetters.end(), tempString) !=
                    correctLetters.end()) //if letter is not already in vector{
                {
                    //If letters exist in vector, do not add again
                } else {
                    correctLetters.push_back(tempString);
                }

            }

        } else {
            if (std::find(incorrectLetters.begin(), incorrectLetters.end(), tempString) !=
                incorrectLetters.end())
            {
                //if incorrect guesses already exist in vector, do not add
            } else {
                incorrectLetters.push_back(tempString);
            }
        }
    }
    if (std::find(incorrectGuesses.begin(), incorrectGuesses.end(), userGuess_UPPER) !=
        incorrectGuesses.end())
    {
        // do nothing
    } else
    {
        incorrectGuesses.push_back(userGuess_UPPER); //adds entire word user guessed to words
    }
    return givenLetters_UPPER;
}

/*
 * Function: printVectorValues
 * Description: Takes in vector and prints entire value of vector
 */
void game::printVectorValues(std::vector<std::string> v)
{
    std::sort(v.begin(), v.end()); // alphabetically sorts

    for (const std::string& x: v)
    {
        std::cout << x << ',' << ' ';
    }
}

/*
 * Function: stringChangeCase
 * Description: Takes string and changes the case
 */
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