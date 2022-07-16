//
// Created by jacob_howard on 7/6/2022.
//

#ifndef TURDLECPP_CONSOLE_H
#define TURDLECPP_CONSOLE_H

#include <string>
#include <fstream>
#include <iostream>


class console {
public:
    //console();
    void welcome();
    void printArt();
    void clearConsole();
    void gameMode(int *difficulty, int *triesAm); //pointers used to return difficulty and triesAmount later
    bool checkIfNum(std::string str);

private:
    enum GAMEMODE_STATE
    {
        EASY = 1,
        MEDIUM = 2,
        HARD = 3
    };
};


#endif //TURDLECPP_CONSOLE_H
