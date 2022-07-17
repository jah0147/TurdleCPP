//
// Created by jacob_howard on 7/6/2022.
//
#include "console.h"

/*
 * Function: Welcome
 * Purpose: Prints the welcome message
 */
void console::welcome()
{
    std::cout<<"\n--------------------------WELCOME TO TURDLE-------------------------\n";
    std::cout<<"The goal of the game is to guess the 5-letter word in 5 tries or less.\n";
    std::cout<<"----------------------------Good Luck!----------------------------\n\n";
}

/*
 * Function: printArt
 * Purpose: Prints the text art
 */
void console::printArt()
{std::string line; //string that holds the line of a text file
    std::ifstream textFile("textFiles/art/art.txt", std::ios::in); //file creation

    if(textFile.is_open()) //checking if file was opened
    {
        while(getline(textFile, line))
        {
            //std::getline(textFile, line);
            std::cout << line << "\n";
        }
    } else {
        std::cout <<"Unable to open the text file..." <<std::endl; //Prints if file was not opened
    }
    textFile.close();
}

bool console::checkIfNum(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (std::isdigit(str[i]) == false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

/*
 * Function: gameMode
 * Purpose: Lets user select game difficulty
 */
void console::gameMode(int *difficulty, int *triesAm)
{
    std::cout << "PLEASE SELECT YOUR DIFFICULTY" <<std::endl;
    std::cout << "-----------------------------" <<std::endl;
    std::cout << "EASY - TYPE 1" <<std::endl;
    std::cout << "MEDIUM - TYPE 2" <<std::endl;
    std::cout << "HARD - TYPE 3" <<std::endl;
    std::cout << "-----------------------------" <<std::endl;

    std::string userInput;
    std::cout << "\nInput:";
    std::cin >> userInput; //gets usr input
    //*difficulty = std::stoi(userInput);

    while (checkIfNum(userInput) == false)
    {
        //We ignore incorrect number and default to easy mode
        /*
        while ((difficulty != three) || (difficulty != two) || (difficulty != one))
        {
            std::cin >> userInput;
            difficulty = std::stoi(userInput);
        }
         */

        //clearConsole();
        std::cout << "That is not a valid input... Please try again" << std::endl;
        std::cout << "Input:";
        std::cin >> userInput;
    }

    *difficulty = std::stoi(userInput); //sets difficulty to an int of user string input

    switch (*difficulty)
    {
        case EASY:
            *triesAm = 10;
            std::cout << "-----------------EASY MODE-----------------" << std::endl;
            std::cout << "You will be given random letters in the word and " << *triesAm << " tries" << std::endl;
            break;

        case MEDIUM:
            *triesAm = 8;
            std::cout << "-----------------MEDIUM MODE-----------------" << std::endl;
            std::cout << "You will be given a random letter in the word and " << *triesAm << " tries" << std::endl;
            break;

        case HARD:
            *triesAm = 5;
            std::cout << "-----------------Hard MODE-----------------" << std::endl;
            std::cout << "You will be given no random letters in the word and " << *triesAm << " tries" << std::endl;
            break;

        default:
            *triesAm = 10;
            *difficulty = EASY;
            std::cout << "That is an invalid Difficulty..." << std::endl;
            std::cout << "The difficulty will be set to EASY by default." << std::endl;
    }
}

/*
 * Function: clearConsole
 * Purpose: Clears the users console
 *
 * Status: Not currently working as intended
 */
void console::clearConsole()
{
    system("CLS");
    //std::cout << std::flush;
    //std::cout << "";
}