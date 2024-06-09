
#ifndef ST7735_H
#define ST7735_H


#include <avr/io.h>
#include <util/delay.h>
#include "spiAVR.h"


#define RES_PIN PB4
#define DC_PIN PD7
#define CS_PIN PB2

#define RES_LOW PORTB &= ~(1 << RES_PIN)
#define RES_HIGH PORTB |= (1 << RES_PIN)
#define DC_LOW PORTD &= ~(1 << DC_PIN)
#define DC_HIGH PORTD |= (1 << DC_PIN)
#define CS_LOW PORTB &= ~(1 << CS_PIN)
#define CS_HIGH PORTB |= (1 << CS_PIN)

#define BLACK  0x0000
#define WHITE  0xFFFF
#define BLUE    0x001f
#define LIGHT_BLUE 0xFF58
#define YELLOW 0xff00
#define GREEN  0x07e0
#define RED   0xf820
#define PURPLE 0xa81f
#define PINK   0xec98
#define ORANGE 0xfd00


void Command(int cmd)
{
    DC_LOW;
    CS_LOW;
    SPI_SEND(cmd);
    CS_HIGH;
}

void Data(int data)
{
    DC_HIGH;
    CS_LOW;
    SPI_SEND(data);
    CS_HIGH;
}

void SetColumnAddress(int start, int end)
{
    Command(0x2A);
    Data(start >> 8);
    Data(start & 0xFF);
    Data(end >> 8);
    Data(end & 0xFF);
}

void SetRowAddress(int start, int end)
{
    Command(0x2B);
    Data(start >> 8);
    Data(start & 0xFF);
    Data(end >> 8);
    Data(end & 0xFF);
}

void WritePixel(int color)
{
    Data((color >> 8) & 0xFF);
    Data(color & 0xFF);
}

void FillScreen(int color)
{
    SetColumnAddress(0, 129);
    SetRowAddress(0, 200);
    Command(0x2C);

    for (int i = 0; i < 128 * 160; ++i){
    // for (int i = 0; i < 25; ++i){
         WritePixel(color);
    }
}

void WriteToScreen ( int startRow, int endRow,  int startColumn, int endColumn, int color ){
    SetColumnAddress(startRow, endRow);
    SetRowAddress(startColumn, endColumn);
    Command(0x2C);

    for (int i = startRow; i < endRow * endColumn; ++i){
         WritePixel(color);
         }
}

#endif