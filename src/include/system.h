#ifndef SYSTEM_INCLUDE
#define SYSTEM_INCLUDE

#include "types.h"

#define KEYSTATE 0x60
#define KEYVALUE 0x65

uint8 inport(uint16);
void outport(uint16,uint8);

#endif
