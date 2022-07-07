//
// Created by jacob_howard on 7/7/2022.
//

#include <fstream>
#include "wordGen.h"
#include "time.h"

std::string wordGen::selectWord()
{
    int lineNumbers = lineNum(); //gets the amount of lines in a file
    std::string wordsArray[lineNumbers];
    int sizeOfArr = sizeof(wordsArray)/ sizeof(wordsArray[0]) - 1; //getting the size of array after created
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
        std::cout << "Error opening file" << std::endl;
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