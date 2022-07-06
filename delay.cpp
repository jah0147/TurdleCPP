//
// Created by jacob_howard on 7/6/2022.
//

#include "delay.h"

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

//takes in number of seconds for delay
void delay::DELAY_IN_SECONDS(int sec) {
    sleep_until(system_clock::now() + seconds(sec));
}