//
// Created by jacob_howard on 7/7/2022.
//

#include <fstream>
#include "wordGen.h"
#include "time.h"

std::string wordGen::selectWord(std::string wordsArray[], unsigned long numOfLinesInFile)
{
    //*numOfLinesInList = lineNum(); //gets the amount of lines in a file
    //*wordsArray[*numOfLinesInList];
    int sizeOfArr = numOfLinesInFile - 1; //sizeof(wordsArray)/ sizeof(wordsArray[0]) - 1; //getting the size of array after created
    std::ifstream File(filename);
    int i = 0;

    if(File.is_open())
    {
        while (File.peek() != EOF) {
            File >> wordsArray[i];
            i++;
        }
    } else
    {
        std::cout << "Error opening word list" << std::endl;
    }
    File.close();
    //creating random chosen word
    srand(time(NULL)); //Randomize seed initialization
    int randNum = rand() % sizeOfArr;
    std::string randChosenWord = wordsArray[randNum]; //chooses a random word in the arrayList
    return randChosenWord;
}

int wordGen::lineNum()
{
    std::string line;   // To read each line from code
    int count=0;    // Variable to keep count of each line
    std::ifstream file(filename);
    if(file.is_open())
    {
        while(file.peek()!=EOF)
        {
            getline(file, line);
            count++;
        }
        file.close();
        //for testing
        //std::cout << "There are " << count << " lines in the file" << std::endl;
    }
    else
    {
        std::cout << "Unable to open the File: " << filename << std::endl;
    }
    return count;
}

std::string wordGen::givenLetters(std::string randWord, int difficulty)
{
    int wordLength = randWord.length();
    std::string randGivenLetters[wordLength];
    std::string letters;
    srand(time(NULL));
    int randNum1 = rand() % wordLength;
    int randNum2 = rand() % wordLength;

    //Creating blank array
    for(int i = 0; i < wordLength; i++)
    {
        randGivenLetters[i] = "_";
    }

    switch (difficulty)
    {
        case EASY:
            //ensures that there are two random letters generated
            while (randNum1 == randNum2)
            {
                randNum2 = rand() % wordLength;
            }
            //Putting the random chosen letters in
            randGivenLetters[randNum1] = randWord[randNum1];
            randGivenLetters[randNum2] = randWord[randNum2];
            std::cout << "Your random given letters are ";
            for (int i = 0; i < wordLength; i++)
            {
                std::cout << randGivenLetters[i];
                if ((i < (wordLength - 1))) //prints spaces
                {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
            break;

        case MEDIUM:
            randGivenLetters[randNum1] = randWord[randNum1];

            std::cout << "Your random given letter is ";
            for (int i = 0; i < wordLength; i++)
            {
                std::cout << randGivenLetters[i];
                if((i < (wordLength - 1))) //prints spaces
                {
                    std::cout <<" ";
                }
            }
            std::cout << std::endl;
            break;

        case HARD:
            //No free letters for hard mode
            break;

        default:
            std::cout << "There was an error with the Difficulty in wordGen::GivenLetters" << std::endl;
            std::cout << "Defaulting to Easy Difficulty..." << std::endl;
            difficulty = EASY;
    }
    std::string randLettersStr = arrayToString(randGivenLetters, wordLength);
    return randLettersStr;
}

std::string wordGen::arrayToString(std::string* array, int size)
{
    std::string s = "";
    for (int i = 0; i < size; i++) {
        s = s + array[i];
    }
    return s;
}