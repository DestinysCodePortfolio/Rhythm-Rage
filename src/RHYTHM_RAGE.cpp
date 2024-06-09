#include "EEPROM.h"
#include "TITLE.h"
#include "ST7735.h"
#include "spiAVR.h"
#include "TREN_AL_SUR.h"
#include "HELL_ABOVE.h"
#include "timerISR.h"
#include "helper.h"
#include "periph.h"
#include "serialATmega.h"
#include "NOTES.h"
#include "OBLIVION.h"

int HighScore;
int SecHighScore;
int ThirdHighScore;
int currNote;
int matrixKey;
int buttonRight;
unsigned int i;

bool A;
bool B;
bool C;
bool D;

uint8_t EEpromaddress = 130;

void HardwareReset()
{
    PORTB = SetBit(PORTB, 4, 0);
    PORTB = SetBit(PORTB, 4, 1);
}

void ST7735_init()
{
    PORTB = SetBit(PORTB, 2, 0);
    PORTD = SetBit(PORTD, 7, 0);
    Command(0x01);
    _delay_ms(10);
    Command(0x11);
    _delay_ms(10);
    Command(0x3A);
    Data(0x05);
    Command(0x36);
    Data(0b00001000);
    _delay_ms(10);
    Command(0x29);
}

#define NUM_TASKS 2

enum Task1
{
    INIT_TASK1,
    WAIT,
    PLAY_HA,
    PLAY_TAS,
    PLAY_OB
};

int Task1_Tick(int state)
{
    matrixKey = ADC_read(0);

    switch (state)
    {
    case INIT_TASK1:
        state = WAIT;
        break;

    case WAIT:
        D = false;
        C = false;
        B = false;
        if (matrixKey < 100 && matrixKey > 50)
        {
            state = PLAY_HA;
        }
        else if (matrixKey > 100 && matrixKey < 120)
        {
            state = PLAY_OB;
        }
        else if (matrixKey < 50)
        {
            state = PLAY_TAS;
        }
        else
        {
            state = WAIT;
        }
        break;

    case PLAY_HA:
        D = false;
        C = true;
        B = false;
        if (currNote < 261)
        {
            state = PLAY_HA;
        }
        else
        {
            state = WAIT;
        }
        break;

    case PLAY_TAS:
        D = true;
        C = false;
        B = false;
        if (currNote < 158)
        {
            state = PLAY_TAS;
        }
        else
        {
            state = WAIT;
        }
        break;

    case PLAY_OB:
        D = false;
        C = false;
        B = true;
        if (currNote < 202)
        {
            state = PLAY_OB;
        }
        else
        {
            state = WAIT;
        }
        break;
    }

    switch (state)
    {
    case INIT_TASK1:
        OCR1A = ICR1;
        currNote = 0;
        break;

    case WAIT:
        OCR1A = ICR1;
        currNote = 0;
        break;

    case PLAY_HA:
        if (currNote < 261)
        {
            if (i <= pgm_read_word(&noteDurations[currNote]))
            {
                ICR1 = (16000000 / (8 * pgm_read_word(&song1[currNote]))) - 1;
                OCR1A = ICR1 / 2;
                i++;
            }
            else
            {
                i = 0;
                currNote++;
            }
        }
        else
        {
            currNote = 0;
            state = WAIT;
        }
        break;

    case PLAY_TAS:
        if (currNote < 159)
        {
            if (i <= pgm_read_word(&noteLength[currNote]))
            {
                ICR1 = (16000000 / (8 * pgm_read_word(&song2[currNote]))) - 1;
                OCR1A = ICR1 / 2;
                i++;
            }
            else
            {
                i = 0;
                currNote++;
            }
        }
        else
        {
            currNote = 0;
            state = WAIT;
        }
        break;

    case PLAY_OB:
        if (currNote < 202)
        {
            if (i <= pgm_read_word(&notesDurOb[currNote]))
            {
                ICR1 = (16000000 / (8 * pgm_read_word(&song3[currNote]))) - 1;
                OCR1A = ICR1 / 2;
                i++;
            }
            else
            {
                i = 0;
                currNote++;
            }
        }
        else
        {
            currNote = 0;
            state = WAIT;
        }
        break;

    default:
        break;
    }
    return state;
}

enum Task2
{
    INIT_TASK2,
    SHOW_TITLE,
    SHOW_HA,
    SHOW_TAS,
    SHOW_OB
};

int Task2_Tick(int state)
{
    switch (state)
    {
    case INIT_TASK2:
        state = SHOW_TITLE;
        break;

    case SHOW_TITLE:
        if (D)
        {
            state = SHOW_TAS;
        }
        else if (C)
        {
            state = SHOW_HA;
        }
        else if (B)
        {
            state = SHOW_OB;
        }
        else
        {
            state = SHOW_TITLE;
        }
        break;

    case SHOW_TAS:
        state = SHOW_TITLE;
        break;

    case SHOW_HA:
        state = SHOW_TITLE;
        break;

    case SHOW_OB:
        state = SHOW_TITLE;
        break;
    }

    switch (state)
    {
    case INIT_TASK2:
        break;

    case SHOW_TITLE:
        // title();
        break;

    case SHOW_HA:
        if (currNote < 261)
        {
            if (currNote == 0)
            {
                FillScreen(BLACK);
            }

            if (currNote % 4 == 0 && i <= pgm_read_word(&noteDurations[currNote]))
            {
                generateRandomArrow();
            }
            else
            {
                FillScreen(BLACK);
            }
        }
        break;

    case SHOW_TAS:
        if (currNote < 159)
        {
            if (currNote == 0)
            {
                FillScreen(BLACK);
                
            }

            if (currNote % 4 == 0 && i <= pgm_read_word(&noteLength[currNote]))
            {
                generateRandomArrow();
            }
            else
            {
                FillScreen(BLACK);
            }
        }
        break;

    case SHOW_OB:
        if (currNote < 202)
        {
            if (currNote == 0)
            {
                FillScreen(BLACK);
            }

            if (i <= pgm_read_word(&notesDurOb[currNote]))
            {
                generateRandomArrow();
            }
            else
            {
                FillScreen(BLACK);
            }
        }
        break;

    default:
        break;
    }

    return state;
}

typedef struct _task
{
    signed char state;
    unsigned long period;
    unsigned long elapsedTime;
    int (*TickFct)(int);
} task;

const unsigned long GCD_PERIOD = 1;
const unsigned long TASK1_PERIOD = 10;
const unsigned long TASK2_PERIOD = 2000;

task tasks[NUM_TASKS];

void TimerISR()
{
    for (unsigned int i = 0; i < NUM_TASKS; i++)
    {
        if (tasks[i].elapsedTime > tasks[i].period)
        {
            tasks[i].state = tasks[i].TickFct(tasks[i].state);
            tasks[i].elapsedTime = 0;
        }
        tasks[i].elapsedTime += GCD_PERIOD;
    }
}

int main(void)
{
    DDRB = 0xFF;
    PORTB = 0x00;

    PORTC = 0xFF;
    DDRC = 0x00;

    DDRD = 0xFF;
    PORTD = 0x00;

    SPI_INIT();
    HardwareReset();
    ST7735_init();
    serial_init(9600);
    ADC_init();

    TCCR0A |= (1 << COM0A1);
    TCCR0A |= (1 << WGM01) | (1 << WGM00);
    TCCR0B = (TCCR0B & 0xF8) | 0x04;
    OCR0A = 255;

    TCCR1A |= (1 << WGM11) | (1 << COM1A1);
    TCCR1B |= (1 << WGM12) | (1 << WGM13) | (1 << CS11);
    ICR1 = 39999;

    OCR1A = ICR1;

    tasks[0].period = TASK1_PERIOD;
    tasks[0].state = INIT_TASK1;
    tasks[0].elapsedTime = tasks[i].period;
    tasks[0].TickFct = &Task1_Tick;
    ++i;

    tasks[1].period = TASK2_PERIOD;
    tasks[1].state = INIT_TASK2;
    tasks[1].elapsedTime = tasks[i].period;
    tasks[1].TickFct = &Task2_Tick;
    ++i;

    TimerSet(GCD_PERIOD);
    TimerOn();

    title();
    while (1)
    {
        serial_println(ADC_read(0));
    }

    return 0;
}
