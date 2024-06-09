
#ifndef TREN_AL_SUR_H
#define TREN_AL_SUR_H

#include"arrows.h"

#include"NOTES.h"

#include <avr/pgmspace.h>

//BPM IS 190 

const int song2[] PROGMEM = {
    NOTE_C5,  //1

    NOTE_D4,  //2
    NOTE_E4,
    NOTE_F4,
    NOTE_C5,

    NOTE_A4, //3

    NOTE_D4, //4
    NOTE_E4,
    NOTE_F4,
    NOTE_E5,

    NOTE_C5, //5

    NOTE_D4, //6
    NOTE_E4, 
    NOTE_F4, 
    NOTE_C5, 

    NOTE_A4, //7

    NOTE_D4, //8
    NOTE_E4,
    NOTE_F4,
    NOTE_E5,

    NOTE_C5, //9

    NOTE_D4, //10
    NOTE_E4,
    NOTE_F4,
    NOTE_C5,

    NOTE_A4, //11

    NOTE_D4, //12
    NOTE_E4,
    NOTE_F4,
    NOTE_E5,

    NOTE_C5, //13
    
    NOTE_D4, //14
    NOTE_E4,
    NOTE_F4,
    NOTE_C5,

    NOTE_A4, //15

    NOTE_D4, //16
    NOTE_E4,
    NOTE_F4,
    NOTE_E5,

    NOTE_E5, //17
    0,
    NOTE_E5,
    0,
    NOTE_E5,
    NOTE_C5,

    NOTE_D5, //18
    NOTE_C5,
    NOTE_A4,
    0,
    NOTE_A4,
    NOTE_C5,
    0,
    NOTE_C5,


    NOTE_E5, //19
    0,
    NOTE_E5,
    0,
    NOTE_E5,
    NOTE_C5,

    
    NOTE_D5, //20
    NOTE_C5,
    NOTE_A4,
    0,
    NOTE_A4,
    NOTE_C5,
    0,
    NOTE_C5,


    
    NOTE_E5, //21
    0,
    NOTE_E5,
    0,
    NOTE_E5,
    NOTE_C5,


    NOTE_D5, //22
    NOTE_C5,
    NOTE_A4,
    0,
    NOTE_A4,
    NOTE_C5,
    0,
    NOTE_C5,

    NOTE_E5, //23
    0,
    NOTE_E5,
    0,
    NOTE_E5,
    NOTE_C5,
    0,
    NOTE_C5,

    NOTE_D5, //24
    NOTE_C5,
    NOTE_A4,
    NOTE_C5,   

    NOTE_E5, // 25
    0,

    NOTE_D4,  //26
    NOTE_E4,
    NOTE_F4,
    NOTE_C5,

    NOTE_A4, //27

    NOTE_D4, //28
    NOTE_E4,
    NOTE_F4,
    NOTE_E5,

    NOTE_C5, //29

    NOTE_D4, //30
    NOTE_E4, 
    NOTE_F4, 
    NOTE_C5, 

    NOTE_A4, //31

    NOTE_D4, //32
    NOTE_E4,
    NOTE_F4,
    NOTE_E5,

    NOTE_E5, //33
    0,
    NOTE_E5,
    0,
    NOTE_E5,
    NOTE_C5,

    NOTE_D5, //34
    NOTE_C5,
    NOTE_A4,
    0,
    NOTE_A4,
    NOTE_C5,

    
    NOTE_E5, //35
    0,
    NOTE_E5,
    0,
    NOTE_E5,
    NOTE_C5,

    
    NOTE_D5, //36
    NOTE_C5,
    NOTE_A4,
    0,
    NOTE_A4,
    NOTE_C5,

    NOTE_E5, //37
    0,
    NOTE_E5,
    0,
    NOTE_E5,
    NOTE_C5,
    
    NOTE_D5, //38
    NOTE_C5,
    NOTE_A4,
    NOTE_C5,
   
    NOTE_E5, //39
    0,
    NOTE_E5,
    0,
    NOTE_E5,
    NOTE_C5,


    NOTE_D5, //40
    NOTE_C5,
    NOTE_A4,
    NOTE_C5,
   
};

    






const int noteLength[] PROGMEM =
    {
    240,  //1

    60,  //2
    60,
    60,
    120,

    120, //3

    60, //4
    60,
    60,
    60,

    240, //5


    60,  //6
    60,
    60,
    120,

    120, //7

    60,  //8
    60,
    60,
    60,

    240, //9

    60,  //10
    60,
    60,
    120,

    120, //11

    60,  //12
    60,
    60,
    60,

    240, //13

    60,  //14
    60,
    60,
    120,

    120, //15

    60,  //16
    60,
    60,
    60,

    60, //17
    0,
    30,
    0,
    90,
    60,

    60, //18
    30,
    60,
    0,
    30,
    30,
    0,
    30,


    60, //19
    0,
    30,
    0,
    90,
    60,

    
    30, //20
    60,
    60,
    0,
    30,
    30,
    0,
    30,


    
    60, //21
    0,
    30,
    0,
    90,
    60,

    60, //22
    30,
    60,
    0,
    30,
    30,
    0,
    30,

    60, //23
    0,
    30,
    0,
    90,
    30,
    30,

    30, //24
    60,
    90,
    60,   

    120, // 25
    120,

    60,  //26
    60,
    60,
    120,

    120, //27

    60,  //28
    60,
    60,
    60,

    240, //29

    60,  //30
    60,
    60,
    120,

    120, //31


    60, //32
    60,
    60,
    60,

    60, //33
    0,
    30,
    0,
    90,
    60,

    60, //34
    30,
    60,
    0,
    30,
    60,

    
     60, //35
    0,
    30,
    0,
    90,
    60,

    
    30, //36
    60,
    60,
    0,
    30,
    60,

    
    
    60, //37
    0,
    30,
    0,
    90,
    60,
    
    30, //38
    60,
    90,
    60,
   
    60, //39
    0,
    30,
    0,
    90,
    60,


    30, //40
    60,
    90,
    60,
        
        
};


#endif