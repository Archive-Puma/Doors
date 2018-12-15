#ifndef SCREEN_INCLUDE
#define SCREEN_INCLUDE

#include "types.h"
#include "string.h"
#include "system.h"

#define WIDTH     80
#define HEIGHT    25
#define OFFSET    2
#define TAB_SIZE  8

struct Pointer {
  uint16  x;
  uint8   y;
  uint8   c;
} pointer;

void nl();
void cls();
void putCh(uint8);
void putStr(string);
void clsLine(uint8);
void checkPointer();
void write(string,uint32);
// void moveCursor(uint16);
void initScreen(uint8,uint8);
void changeColor(uint8,uint8);

#endif
