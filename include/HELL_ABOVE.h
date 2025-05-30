

#ifndef HELL_ABOVE_H
#define HELL_ABOVE_H
#include "arrows.h"
#include "NOTES.h"

#include "ST7735.h"

#include <avr/pgmspace.h>

const int song1[] PROGMEM  = {

    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    NOTE_CS5,
    NOTE_B4,
    NOTE_AS4,
    NOTE_GS4,
    NOTE_FS4,
    NOTE_GS4,
    NOTE_AS4,

    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    NOTE_CS5,
    NOTE_B4,
    NOTE_AS4,
    NOTE_GS4,
    NOTE_FS4,
    NOTE_GS4,
    NOTE_E4,

    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    NOTE_CS5,
    NOTE_B4,
    NOTE_AS4,
    NOTE_GS4,
    NOTE_FS4,
    NOTE_GS4,
    NOTE_AS4,

    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    NOTE_CS5,
    NOTE_B4,
    NOTE_AS4,
    NOTE_GS4,
    NOTE_FS4,
    NOTE_GS4,
    NOTE_E4,

    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    NOTE_CS5,
    NOTE_B4,
    NOTE_AS4,
    NOTE_GS4,
    NOTE_FS4,
    NOTE_GS4,
    NOTE_AS4,

    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    NOTE_CS5,
    NOTE_B4,
    NOTE_AS4,
    NOTE_GS4,
    NOTE_FS4,
    NOTE_GS4,
    NOTE_E4,

    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_GS4,
    0,
    NOTE_GS4,
    0,
    NOTE_GS4,
    0,
    NOTE_GS4,
    0,
    NOTE_AS4,
    0,
    NOTE_AS4,
    0,
    NOTE_AS4,
    0,
    NOTE_AS4,

    0,
    NOTE_B4,
    0,
    NOTE_B4,
    0,
    NOTE_B4,
    0,
    NOTE_B4,
    0,
    NOTE_B4,
    0,
    NOTE_B4,
    0,
    NOTE_AS4,
    0,
    NOTE_AS4,
    0,
    NOTE_GS4,
    0,
    NOTE_GS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_CS4,
    0,
    NOTE_CS4,
    0,
    NOTE_B3,
    0,
    NOTE_B3,
    0,
    NOTE_AS3,
    0,
    NOTE_AS3,

    0,
    NOTE_CS4,
    0,
    NOTE_CS4,
    0,
    NOTE_CS4,
    0,
    NOTE_CS4,
    0,
    NOTE_CS4,
    0,
    NOTE_CS4,
    0,
    NOTE_CS4,
    0,

    NOTE_CS4,
    0,
    NOTE_CS4,
    NOTE_B3,
    NOTE_CS4,
    NOTE_B3,

    0,
    NOTE_CS4,
    0,
    NOTE_CS4,
    0,
    NOTE_CS4,
    0,
    NOTE_CS4,
    0,
    NOTE_CS4,
    0,
    NOTE_CS4,
    0,
    NOTE_CS4,

    NOTE_E4,
    NOTE_D4,
    NOTE_CS4,
    NOTE_B4,

    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,

    NOTE_GS4,
    0,
    NOTE_GS4,
    NOTE_FS4,
    NOTE_AS4,
    NOTE_GS4,

    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,

    NOTE_CS5,
    NOTE_B4,
    NOTE_AS4,
    NOTE_GS4,

    NOTE_B4,
    NOTE_AS4,
    NOTE_GS4,

    NOTE_B4,
    NOTE_AS4,
    NOTE_GS4,

    NOTE_AS4,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,

    NOTE_CS4,
    NOTE_B4,
    NOTE_AS4,
    NOTE_GS4,

    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    0,
    NOTE_FS4,
    NOTE_CS5,

    NOTE_B4,
    NOTE_AS4,
    NOTE_B4,
    NOTE_AS4,

    0,
    NOTE_B4,
    0,
    NOTE_B4,
    0,
    NOTE_B4,
    0,
    NOTE_B4,
    0,
    NOTE_B4,
    NOTE_AS4,

    NOTE_CS5,
    NOTE_FS4,
    0,
    NOTE_FS4,
    NOTE_AS4,
    NOTE_FS4

};

const int noteDurations[] PROGMEM =
    {
    15, 0, 15, 0, 15, 30, 30, 30, 30, 15, 30, 30,
    15, 0, 15, 0, 15, 30, 30, 30, 30, 15, 30, 30,
    15, 0, 15, 0, 15, 30, 30, 30, 30, 15, 30, 30,
    15, 0, 15, 0, 15, 30, 30, 30, 30, 15, 30, 30,
    15, 0, 15, 0, 15, 30, 30, 30, 30, 15, 30, 30,
    15, 0, 15, 0, 15, 30, 30, 30, 30, 15, 30, 30,

    15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15,
    0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15, 0, 15,
    60, 30, 0, 30, 0, 30, 0, 30, 0, 30, 0, 30, 0, 30, 0,
    45, 0, 45, 30, 60, 60,
    30, 30, 0, 30, 0, 30, 0, 30, 0, 30, 0, 30, 0, 30,
    60, 60, 60, 60,
    30, 30, 0, 30, 0, 30, 0, 30, 0, 30, 0, 30, 0, 30,
    45, 0, 45, 30, 60, 60,
    30, 30, 0, 30, 0, 30, 0, 30, 0, 30, 0, 30, 0, 30,
    60, 60, 60, 60,
    90, 90, 90,
    90, 90, 90,
    60, 60, 0, 60, 0, 60,
    60, 60, 60, 60,
    30, 0, 30, 0, 30, 0, 30, 0, 45, 0, 45, 30,
    60, 60, 60, 60,
    30, 30, 0, 30, 0, 30, 0, 45, 0, 45, 30,
    90, 30, 0, 45, 45, 30
    
        };

#endif