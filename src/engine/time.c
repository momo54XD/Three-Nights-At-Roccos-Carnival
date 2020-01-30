#include "types.h"

#include <time.h>
#include <stdio.h>

float Current_Tsecond;
u16_t Current_Second;

void Time_Tick() {
    Current_Tsecond += (float)10/6;

    if (Current_Tsecond >= 100) {
        Current_Second++;
        Current_Tsecond = 0;
    }
}

void delay(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    while (goal > clock());
}