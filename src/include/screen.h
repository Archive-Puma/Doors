#ifndef SCREEN_INCLUDE
#define SCREEN_INCLUDE

#include "types.h"
#include "string.h"

void nl();
void cls();
void checkPointer();
void putCh(uint8 ch);
void putStr(string str);
void clsLine(uint8 line);

#endif
