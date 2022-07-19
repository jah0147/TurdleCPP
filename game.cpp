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

              // Checks if word exists in wordlist
              //currently not working - needs fix
              //
//            if (difficulty != 1) //if the difficulty is not set to easy (this is a mess)
//            {
//                bool realWord = false;
//                while (!realWord)
//                {
//                    for (int i = 0; i < arrayLength; i++) {
//                        if ((randWord_UPPER[i].find(userGuess_UPPER) !=
//                             std::string::npos)) //checks to see if word exists in wordbank
//                        {
//                            realWord = true;
//                        }
//                    }
//                }
//            }

            //User guessed Correct Word
            if (userGuess_UPPER == randWord_UPPER) {
                console::clearConsole();
                std::string continueUsrInput;
                std::cout << "---------------------------------------***CORRECT***---------------------------------------" << std::endl;
                std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "                                     The word was " << randWord_UPPER << std::endl;
                std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
                std::cout << "----------------------------------------***SCORE***----------------------------------------" << std::endl;

                int GAME_SCORE = score(tries); //stores score for entire game
                std::cout << "                                   Your score is: " << GAME_SCORE << " points!" << std::endl;
                std::cout << "-------------------------------------------------------------------------------------------" << std::endl;

                if (didCheat) { //If the user used the cheat command
                    std::cout << "-------------------------------------------CHEATER-------------------------------------" << std::endl;
                    std::cout << "                          You did cheat though... Not very impressive" << std::endl;
                    std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
                }

                done = true;
                delay.DELAY_IN_SECONDS(2);
            } else {
                console::clearConsole();
                givenLetters_UPPER = compairGuess(userGuess_UPPER,
                                                  randWord_UPPER,
                                                  givenLetters_UPPER);


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

                userGuess = userInputCase(tries, quit); //Checks if user inputs a command or just a word

                while ((userGuess[0]== '/') & (!quit)) //if user input command. ask for guess again
                {
                    userGuess = userInputCase(tries, quit); //Checks if user inputs a command or just a word
                }
                if (!quit) {
                    while (userGuess.length() != randWord.length()) {
                        console::clearConsole();

                        std::cout << "Please type no more or less than "
                                  << randWord.length() << " letters!" << std::endl;
                        std::cout << "Please try again..." << std::endl;
                        userGuess = userInputCase(tries, quit);
                    }
            }

            tries--;
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
            console::clearConsole();
            std::cout << std::endl;
            std::cout << "You have ran out of tries..." << std::endl;
            std::cout << "The word was " << randWord_UPPER << std::endl;
            std::cout << "\n         Game Over";
            continueGame = false;
            delay.DELAY_IN_SECONDS(3);
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
        else {usrCommand = NOTCOMMAND;} //if user inputs a non-existent command
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