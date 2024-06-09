#ifndef TITLE_H
#define TITLE_H

#include"ST7735.h"


void title() {
  FillScreen(BLACK);
 
  WriteToScreen (20, 22, 10, 30 ,RED );  //P
  WriteToScreen (20,30,   9, 10 ,ORANGE );
  WriteToScreen (30, 32, 10, 12 ,YELLOW );
  WriteToScreen (30, 32, 10, 12 ,GREEN );
  WriteToScreen (32, 34, 12, 19 ,BLUE );
  WriteToScreen (23, 31, 18, 20 ,PURPLE );

  WriteToScreen (28, 30, 21, 22 ,RED ); // DIAG
  WriteToScreen (30, 32, 22, 24 ,ORANGE );
  WriteToScreen (32, 34, 24, 26 ,YELLOW );
  WriteToScreen (34, 36, 26, 28 ,GREEN );
  WriteToScreen (36, 38, 28, 30 ,BLUE );

  WriteToScreen (43, 45, 10, 30 ,RED ); // h
  WriteToScreen (45, 50, 19, 20 ,ORANGE );
  WriteToScreen (50, 52, 20, 30 ,YELLOW );


  
  WriteToScreen (57, 62, 29, 30 ,GREEN ); // y
  WriteToScreen (56, 57, 20, 30 ,BLUE );
  WriteToScreen (62, 64, 20, 40 ,PURPLE );

  WriteToScreen (69, 71, 10, 30 ,PINK ); //t
  WriteToScreen (65, 75, 15, 16 ,RED );

  
  WriteToScreen (77, 79, 10, 30 ,ORANGE ); // h
  WriteToScreen (79, 84, 19, 20 ,YELLOW );
  WriteToScreen (84, 86, 20, 30 ,GREEN );

  WriteToScreen (90, 92, 20, 30 ,BLUE ); //m
  WriteToScreen (92 ,96, 18, 19 ,PURPLE );
  WriteToScreen (96, 97, 20, 30 ,RED );
  WriteToScreen (101, 103, 20, 30 ,ORANGE );
   WriteToScreen (97 ,101, 18, 19 ,YELLOW ); 

  WriteToScreen (20, 22, 50, 70 ,GREEN );  //P
  WriteToScreen (20, 30, 49, 50 ,BLUE );
  WriteToScreen (30, 32, 50, 52 ,PURPLE );
  WriteToScreen (32, 34, 52, 59 ,RED );
  WriteToScreen (23, 31, 58, 60 ,ORANGE );

  WriteToScreen (28, 30,61, 62 ,RED ); // DIAG
  WriteToScreen (30, 32,62, 64 ,ORANGE );
  WriteToScreen (32, 34,64, 66 ,YELLOW );
  WriteToScreen (34, 36,66, 68 ,GREEN );
  WriteToScreen (36, 38,68, 70 ,RED );

  WriteToScreen (45, 50, 54, 55 ,ORANGE );
  WriteToScreen (43, 45, 60, 69 ,YELLOW ); // a
  WriteToScreen (45, 50, 59, 60 ,PINK );
  WriteToScreen (50, 52, 55, 70 ,ORANGE );
  WriteToScreen (46, 50, 68, 69 ,GREEN );

 
  WriteToScreen(58, 60, 60, 69, BLUE); // g
  WriteToScreen(60, 65, 59, 60, PINK);
  WriteToScreen(61, 65, 68, 69, PURPLE);
  WriteToScreen(66, 68, 60, 79, RED);
  WriteToScreen(60, 65, 78, 79, ORANGE);

  WriteToScreen (75, 80, 54, 55 ,YELLOW ); // e
  WriteToScreen (75, 80, 64, 65, GREEN);
  WriteToScreen (73, 75, 56, 71 ,BLUE ); 
  WriteToScreen (80, 81, 55, 65 ,PURPLE ); 
  WriteToScreen (75, 80, 70, 71 ,RED );

}

#endif