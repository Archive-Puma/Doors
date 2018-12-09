#ifndef SCREEN_INCLUDE
#define SCREEN_INCLUDE

#include "types.h"

const uint8 width = 80, height = 25, size = 2;
uint8 pointerX = 0, pointerY = 0, color = 0x0F;

void putCh(uint8 ch) {
  uint8 position = 0;
  string screen = (string) 0x000B8000;
  
  switch(ch) {
    default:
      position = (pointerX + pointerY * width) * size;
      screen[position] = ch;
      screen[position+1] = color;
      pointerX++;
      break;
  }
}

#endif