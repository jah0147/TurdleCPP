//
// Created by Jacob_howard on 7/12/2022.
//

#ifndef TURDLECPP_KEEPSCORE_H
#define TURDLECPP_KEEPSCORE_H

#endif //TURDLECPP_KEEPSCORE_H

int newScore = 0;

inline int score(int addScore, bool RESET)
{
    if (!RESET) {
        newScore += addScore;
    } else {
        newScore = 0;
    }
    return newScore;
}