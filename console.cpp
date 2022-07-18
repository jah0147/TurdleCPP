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
    std::cout<<"\n------------------------------WELCOME TO TURDLE-----------------------------" << std::endl;
    std::cout<<"The goal of the game is to guess the randomly selected word in so many tries" << std::endl;
    std::cout<<"----------------------------------Good Luck!----------------------------------" << std::endl;
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
    bool bCheckIfNumb;
    for (int i = 0; i < str.length(); i++)
    {
        if (std::isdigit(str[i]) == false)
        {
            bCheckIfNumb = false;
        }
        else
        {
            bCheckIfNumb = true;
        }
    }
    return bCheckIfNumb;
}

/*
 * Function: gameMode
 * Purpose: Lets user select game difficulty
 */
void console::gameMode(int *difficulty, int *triesAm)
{
    //std::cout << "PLEASE SELECT YOUR DIFFICULTY" <<std::endl;
    std::cout<<"------------------------------PLEASE SELECT YOUR DIFFICULTY------------------------------" << std::endl;
    std::cout << "                                  [1] EASY - TYPE 1" <<std::endl;
    std::cout << "                                  [2] MEDIUM - TYPE 2" <<std::endl;
    std::cout << "                                  [3] HARD - TYPE 3" <<std::endl;
    std::cout << "----------------------------------------------------------------------------------------" <<std::endl;

    std::string userInput;
    std::cout << "\nInput:";
    std::cin >> userInput; //gets usr input


    while (checkIfNum(userInput) == false)
    {
        console::clearConsole();
        std::cout << "That is not a valid input... Please try again" << std::endl;
        std::cout << "Input:";
        std::cin >> userInput;
    }

    *difficulty = std::stoi(userInput); //sets difficulty to an int of user string input
    console::clearConsole(); //clears console after user inputs a difficulty
    switch (*difficulty)
    {
        case EASY:
            *triesAm = 10;
            std::cout << "-----------------EASY MODE-----------------" << std::endl;
            std::cout << "You will be given random letters in the word and " << *triesAm << " tries" << std::endl;
            std::cout << "\nFeel free to type '/quit' at any time to quit the game." << std::endl;
            break;

        case MEDIUM:
            *triesAm = 8;
            std::cout << "-----------------MEDIUM MODE-----------------" << std::endl;
            std::cout << "You will be given a random letter in the word and " << *triesAm << " tries" << std::endl;
            std::cout << "\nFeel free to type '/quit' at any time to quit the game." << std::endl;
            break;

        case HARD:
            *triesAm = 5;
            std::cout << "-----------------Hard MODE-----------------" << std::endl;
            std::cout << "You will be given no random letters in the word and " << *triesAm << " tries" << std::endl;
            std::cout << "\nFeel free to type '/quit' at any time to quit the game." << std::endl;
            break;

        default:
            *triesAm = 10;
            *difficulty = EASY;
            std::cout << "That is an invalid Difficulty..." << std::endl;
            std::cout << "The difficulty will be set to EASY by default." << std::endl;
            std::cout << "You will be given random letters in the word and " << *triesAm << " tries" << std::endl;
            std::cout << "\nFeel free to type '/quit' at any time to quit the game." << std::endl;
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

}