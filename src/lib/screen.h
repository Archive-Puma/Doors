#ifndef SCREEN_INCLUDE
#define SCREEN_INCLUDE

#include "types.h"
#include "string.h"

const string screen = (string) 0x000B8000;
const uint8 width = 80, height = 25, size = 2;
uint8 pointerX = 0, pointerY = 0, color = 0x7F;

void test() {
  screen[0]   = '0';
  screen[1]   = 0x1F;
  screen[160] = '1';
  screen[161] = 0x2F;
  screen[320] = '2';
  screen[321] = 0x3F;
  screen[480] = '3';
  screen[481] = 0x4F;
}

void nl() {
  pointerY++;
  pointerX = 0;
}

void checkPointer() {
  if(pointerX >= width)
    nl();
}

void putCh(uint8 ch) {
  uint16 position;
  
  switch(ch) {
    case '\n':
      nl();
      break;
    case '\t':
      uint8 space;
      for(space = 0; space < 8; space++)
        putCh(' ');
      break;
    default:
      position = (pointerX + pointerY * width) * size;
      screen[position] = ch;
      screen[position+1] = color;
      pointerX++;
      break;
  }

  checkPointer();
}

void putStr(string str) {
  uint8 ch;
  for(ch = 0; ch < len(str); ch++)
    putCh(str[ch]);
}

void clsLine(uint8 line) {
  uint16 position;
  uint16 origin = line * width * size;
  for(position = origin; position < origin + width * size; position++) {
    screen[position++] = ' ';
    screen[position] = color;
  }
}

void cls() {
  uint8 line;
  for(line = 0; line < height; line++)
    clsLine(line);
}

#endif
