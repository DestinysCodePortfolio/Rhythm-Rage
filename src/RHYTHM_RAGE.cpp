#include <avr/eeprom.h>
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

   int arrowCounter = 0; // Counter to track arrow duration

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

#define EEPROM_ADDR_OB 0
#define EEPROM_ADDR_HA 4
#define EEPROM_ADDR_TAS 8

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
#define NUM_TASKS 5

enum Task1
{
    INIT_TASK1,
    WAIT
};

enum Task2
{
    INIT_TASK2,
    PLAY_OB,
    SILENT_OB
};

enum Task3
{
    INIT_TASK3,
    PLAY_HA,
    SILENT_HA
};

enum Task4
{
    INIT_TASK4,
    PLAY_TAS,
    SILENT_TAS
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
        if (matrixKey < 100 && matrixKey > 50)
        {
            C = true; // HELL_ABOVE
        }
        else if (matrixKey > 100 && matrixKey < 120)
        {
            B = true; // OBLIVION
        }
        else if (matrixKey < 50)
        {
            D = true; // TREN_AL_SUR
        }
        break;

    default:
        break;
    }
    return state;
}

int Task2_Tick(int state)
{
    switch (state)
    {
    case INIT_TASK2:
        if (B)
        {
            state = PLAY_OB;
            currNote = 0;
            i = 0;
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
            state = SILENT_OB;
        }
        break;

    case SILENT_OB:
        OCR1A = 0; // Silence the buzzer
        B = false;
        state = INIT_TASK2;
        break;

    default:
        break;
    }
    return state;
}

int Task3_Tick(int state)
{
    switch (state)
    {
    case INIT_TASK3:
        if (C)
        {
            state = PLAY_HA;
            currNote = 0;
            i = 0;
        }
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
            state = SILENT_HA;
        }
        break;

    case SILENT_HA:
        OCR1A = 0; // Silence the buzzer
        C = false;
        state = INIT_TASK3;
        break;

    default:
        break;
    }
    return state;
}

int Task4_Tick(int state)
{
    switch (state)
    {
    case INIT_TASK4:
        if (D)
        {
            state = PLAY_TAS;
            currNote = 0;
            i = 0;
        }
        break;

    case PLAY_TAS:
        if (currNote < 158)
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
            state = SILENT_TAS;
        }
        break;

    case SILENT_TAS:
        OCR1A = 0; // Silence the buzzer
        D = false;
        state = INIT_TASK4;
        break;

    default:
        break;
    }
    return state;
}

enum Task5
{
    INIT_TASK5,
    IDLE,
    SHOW_HA,
    SHOW_TAS,
    SHOW_OB
};

int Task5_Tick(int state)
{

    switch (state)
    {
    case INIT_TASK5:
        state = IDLE;
        break;

    case IDLE:
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
            state = IDLE;
        }
        break;

    case SHOW_TAS:
        state = IDLE;
        break;

    case SHOW_HA:
        state = IDLE;
        break;

    case SHOW_OB:
        state = IDLE;
        break;
    }

    switch (state)
    {
    case INIT_TASK5:
        break;

    case IDLE:
        // Display the title screen
        // title();
        break;

    case SHOW_HA:
     
        if (currNote < 261)
        {
      if (arrowCounter == 0)
            {

                generateRandomArrow(); // Generate a new arrow
            }

            updateArrowState(); // Update the arrow state

            arrowCounter++;
            if (arrowCounter >= arrowDuration)
            {
                arrowCounter = 0;
            }
        }
        break;

    case SHOW_TAS:
        if (currNote < 159)
        {
          if (arrowCounter == 0)
            {

                generateRandomArrow(); // Generate a new arrow
            }

            updateArrowState(); // Update the arrow state

            arrowCounter++;
            if (arrowCounter >= arrowDuration)
            {
                arrowCounter = 0;
            }
        }
        break;

    case SHOW_OB:
        if (currNote < 202)
        {
   
           if (currNote == 0)
            {

                FillScreen(BLACK); // Generate a new arrow
            }

            if (arrowCounter == 0)
            {

                generateRandomArrow(); // Generate a new arrow
            }

            updateArrowState(); // Update the arrow state

            arrowCounter++;
            if (arrowCounter >= arrowDuration)
            {
                arrowCounter = 0;
            }
        }
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
const unsigned long TASK2_PERIOD = 10;
const unsigned long TASK3_PERIOD = 13;
const unsigned long TASK4_PERIOD = 10;
const unsigned long TASK5_PERIOD = 1000;


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


    tasks[2].period = TASK3_PERIOD;
    tasks[2].state = INIT_TASK3;
    tasks[2].elapsedTime = tasks[i].period;
    tasks[2].TickFct = &Task3_Tick;
    ++i;

    
    tasks[3].period = TASK4_PERIOD;
    tasks[3].state = INIT_TASK4;
    tasks[3].elapsedTime = tasks[i].period;
    tasks[3].TickFct = &Task4_Tick;
    ++i;

    
    tasks[4].period = TASK5_PERIOD;
    tasks[4].state = INIT_TASK5;
    tasks[4].elapsedTime = tasks[i].period;
    tasks[4].TickFct = &Task5_Tick;
    ++i;


    TimerSet(GCD_PERIOD);
    TimerOn();

    title();
    while (1)
    {
        serial_println(B);
    }

    return 0;
}
