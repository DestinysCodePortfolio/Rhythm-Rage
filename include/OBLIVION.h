
#ifndef OBLIVION_H
#define OBLIVION_H
#include "arrows.h"
#include "NOTES.h"

#include <avr/pgmspace.h>

const int song3[] PROGMEM = {

NOTE_D2, //1
0,
NOTE_D2,
NOTE_D3,
NOTE_A2,
NOTE_D2,
0,
NOTE_D2,
0,
NOTE_D2,
NOTE_A2,


NOTE_D2, //2
0,
NOTE_D2,
NOTE_D3,
NOTE_A2,
NOTE_D2,
NOTE_D3,
NOTE_A2,
0,
NOTE_A2,


NOTE_D2, //3
0,
NOTE_D2,
NOTE_D3,
NOTE_A2,
NOTE_D2,
0,
NOTE_D2,
0,
NOTE_D2,
NOTE_A2,


NOTE_D2,  //4
0, 
NOTE_D2,
NOTE_D3,
NOTE_A2,
NOTE_D2,
NOTE_D3,
NOTE_A2,
0,
NOTE_A2,


NOTE_B1,  //5
0,
NOTE_B1,
NOTE_B2,
NOTE_FS2,
NOTE_B1,
0,
NOTE_B1,
0,
NOTE_B1,
NOTE_FS2,


NOTE_B1, //6
0,
NOTE_B1,
NOTE_B2,
NOTE_FS2,
NOTE_B1,
0,
NOTE_B2,
0,
NOTE_B1,
NOTE_FS2,
0,
NOTE_FS2,


NOTE_B1,  //7
0,
NOTE_B1,
NOTE_B2,
NOTE_FS2,
NOTE_B1,
0,
NOTE_B1,
0,
NOTE_B1,
NOTE_FS2,

NOTE_B1,  //8
0,
NOTE_B1,
NOTE_B2,
NOTE_FS2,
NOTE_B1,
0,
NOTE_B2,
0,
NOTE_B1,
NOTE_FS2,
0,
NOTE_FS2,



NOTE_D2,  //9
0, 
NOTE_D2,
NOTE_D3,
NOTE_A2,
NOTE_D2,
0,
NOTE_D2,
0,
NOTE_D2,
NOTE_A2,

NOTE_D2,
0,
NOTE_D2,
NOTE_D3,
NOTE_A2,
NOTE_D2,
NOTE_D3,
NOTE_A2,
0,
NOTE_A2,



NOTE_D2,  //10
0,
NOTE_D2,
NOTE_D3,
NOTE_A2,
NOTE_D2,
0,
NOTE_D2,
0,
NOTE_D2,
NOTE_A2,

NOTE_D2,  //11
0,
NOTE_D2,
NOTE_D3,
NOTE_A2,
NOTE_D2,
NOTE_D3,
NOTE_A2,
0,
NOTE_A2,


NOTE_B1,  //12
0,
NOTE_B1,
NOTE_B2,
NOTE_FS2,
NOTE_B1,
0,
NOTE_B1,
0,
NOTE_B1,
NOTE_FS2,
 
NOTE_B1,  //13
0, 
NOTE_B1,
NOTE_B2,
NOTE_FS2,
NOTE_B1,
0,
NOTE_B2,
0,
NOTE_B1,
NOTE_FS2,
0,
NOTE_FS2,

//SEPRERATE
NOTE_FS4,  //14
NOTE_A5,
0,
NOTE_A5,
NOTE_B5,

NOTE_B5,
NOTE_FS5,
0,
NOTE_FS5,
0, // 30 


NOTE_B5,  //15
NOTE_FS5,
0,
NOTE_FS5,
0,
NOTE_FS5,

NOTE_D5, //16
NOTE_CS5,
NOTE_B4,
NOTE_A4,

NOTE_FS4, //17
0,
NOTE_FS4,
NOTE_E4,
NOTE_D4,

NOTE_E4, //18
NOTE_FS4,
NOTE_D4,
0, //60

NOTE_FS4, //19
NOTE_E4,
NOTE_D4,
NOTE_E4,
NOTE_FS4,
NOTE_E4,
NOTE_D4,
NOTE_E4,

NOTE_FS4, //20
NOTE_E4,
NOTE_D4,
NOTE_E4,
NOTE_FS4,
NOTE_E4,
NOTE_D4,
NOTE_E4,

NOTE_D4








};

const int notesDurOb [] PROGMEM{

    30, 0, 30, 30, 30, 30, 0, 30, 0, 30, 30,
    30, 0, 30, 30, 30, 30, 30, 30, 0, 30,
    30, 0, 30, 30, 30, 30, 0, 30, 0, 30, 30,
    30, 0, 30, 30, 30, 30, 30, 30, 0, 30,
    30, 0, 30, 30, 30, 30, 0, 30, 0, 30, 30,
    30, 0, 30, 30, 30, 30, 0, 30, 0, 30, 30, 0, 30,
    30, 0, 30, 30, 30, 30, 0, 30, 0, 30, 30,
    30, 0, 30, 30, 30, 30, 0, 30, 0, 30, 30, 0, 30,
    30, 0, 30, 30, 30, 30, 0, 30, 0, 30, 30,
    30, 0, 30, 30, 30, 30, 30, 30, 0, 30,
    30, 0, 30, 30, 30, 30, 0, 30, 0, 30, 30,
    30, 0, 30, 30, 30, 30, 30, 30, 0, 30,
    30, 0, 30, 30, 30, 30, 0, 30, 0, 30, 30,
    30, 0, 30, 30, 30, 30, 0, 30, 0, 30, 30, 0, 30,
    90, 30, 0, 90, 30,
    90, 30, 0, 90, 30,
    90, 30, 0, 90, 0, 30,
    60, 60, 60, 60,
    120, 0, 60, 30, 30,
    60, 60, 60, 60,
    30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
    90
};

#endif