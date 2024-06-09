
#ifndef ARROWS_H
#define ARROWS_H
#include "ST7735.h"
#include <stdlib.h>
#include "periph.h"

bool left;
bool right;
bool up;
bool down;
int j = 0;
bool wait;
int streak;
int score;
int yOffset = 0;



void streakAndScore(int streak) {
        if (streak > 3) {
            score += 3;
        } else {
            streak++;
            score += 1;
        }
}
void arrowLeft() {
WriteToScreen(62, 64, 24, 26, GREEN);
WriteToScreen(64, 66, 26, 28, GREEN);
WriteToScreen(66, 68, 28, 30, GREEN);
WriteToScreen(58, 60, 35, 37, GREEN); // DIAG
WriteToScreen(60, 62, 34, 36, GREEN);
WriteToScreen(62, 64, 33, 35, GREEN);
WriteToScreen(64, 66, 32, 34, GREEN);
WriteToScreen(66, 68, 31, 33, GREEN);
WriteToScreen(67, 70, 31, 32, GREEN);
WriteToScreen(50, 70, 29, 30, GREEN);

}


void arrowRight() {
    WriteToScreen(58 , 60, 22 +20, 23 +20, RED); // DIAG
    WriteToScreen(60, 62, 23 +20, 25 +20, RED);
    WriteToScreen(62, 64, 25 +20, 27 +20, RED);
    WriteToScreen(64, 66, 27 +20, 29 +20, RED);
    WriteToScreen(66, 68, 29 +20, 30 +20, RED);
    WriteToScreen(58, 60, 15 +20, 17 +20, RED); // DIAG
    WriteToScreen(60, 62, 14 +20, 16 +20, RED);
    WriteToScreen(62, 64, 13 +20, 15 +20, RED);
    WriteToScreen(64, 66, 12 +20, 14 +20, RED);
    WriteToScreen(66, 68, 11 +20, 13 +20, RED);
    WriteToScreen(67, 70, 11 +20, 12 +20, RED);
    WriteToScreen(62, 80, 28  +20- 10, 30 +20 - 10, RED);
}


void arrowUp() {
    WriteToScreen(50, 52, 10, 30, YELLOW); // DIAG
    // WriteToScreen(48, 70, 11, 13, YELLOW);
    WriteToScreen(46, 48, 14, 16, YELLOW);
    WriteToScreen(44, 46, 17, 19, YELLOW);
    WriteToScreen(42, 44, 20, 22, YELLOW);
    WriteToScreen(46 + 10 - 1, 48 + 10 - 1, 14, 16, YELLOW);
    WriteToScreen(44 + 14 - 1, 46 + 14 - 1, 17, 19, YELLOW);
    WriteToScreen(42 + 18 - 1, 44 + 18 - 1, 20, 22, YELLOW);
}


void arrowDown() {
    WriteToScreen(50, 52, 10, 30, BLUE); // DIAG
    // WriteToScreen(48, 70, 28, 29, BLUE);
    WriteToScreen(46, 48, 26, 28, BLUE);
    WriteToScreen(44, 46, 24, 26, BLUE);
    WriteToScreen(42, 44, 22, 24, BLUE);
    WriteToScreen(46 + 9, 48 + 9, 26, 28, BLUE);
    WriteToScreen(48 + 9, 50 + 9, 24, 26, BLUE);
    WriteToScreen(50 + 9, 52 + 9, 22, 24, BLUE);
}


void generateRandomArrow()
{
    int randomArrow = rand() % 4;
    switch (randomArrow)
    {
    case 0:
        arrowLeft();
        if ( ADC_read(0) > 450 && ADC_read(0) < 470  ){
        streakAndScore(streak);
        }
        break;
    case 1:
        arrowRight();
         if ( ADC_read(0) > 268 && ADC_read(0) < 270  ){
        streakAndScore(streak);
         }
        break;
    case 2:
        arrowUp();
        if ( ADC_read(0) > 990 && ADC_read(0) < 1005  ){
        streakAndScore(streak);
        }
        break;
    case 3:
        arrowDown();
        if ( ADC_read(0) > 250 && ADC_read(0) <= 268  ){
        streakAndScore(streak);
         }
        break;
    }
        FillScreen(BLACK);
}






#endif























































































































































