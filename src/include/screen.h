#ifndef SCREEN_INCLUDE
#define SCREEN_INCLUDE

#include "types.h"
#include "string.h"
#include "system.h"

void nl();
void cls();
void putCh(uint8);
void putStr(string);
void clsLine(uint8);
void checkPointer();
void changeColor(uint8,uint8);

#endif
