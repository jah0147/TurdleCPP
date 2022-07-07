//
// Created by jacob_howard on 7/7/2022.
//

#ifndef TURDLECPP_GAME_H
#define TURDLECPP_GAME_H

#include <string>

class game{
public:
    void guessWord(int tries,
                   std::string randWord,
                   std::string givenLetters);
    bool contunueGame(bool Continue);

private:
    enum CONTINUE_STATE
    {
        YES = true,
        NO = false
    };
};


#endif //TURDLECPP_GAME_H
