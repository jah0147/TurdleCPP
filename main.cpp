//global includes
#include <iostream>
#define TESTING //Comment this out when not testing
//My include files
#include "console.h"
#include "delay.h"

int main() {
console console;
delay delay;

console.printArt();
console.welcome();

delay.DELAY_IN_SECONDS(3); //3 second delay
//console.clearConsole(); //should clear console screen



//Tests
#ifdef TESTING
std::string freeLetter = "Tests";
int difficulty, triesAm;
console.gameMode(freeLetter, &difficulty, &triesAm);
std::cout << "\nthe difficulty chosen is: " << difficulty << std::endl;
std::cout << "The triesAmount is: " << triesAm << std::endl;
#endif
    return 0;
}
