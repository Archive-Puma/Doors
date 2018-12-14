#include "string.h"

uint8 len(string str) {
  uint8 length = 0;
  while(str[++length] != 0);
  return length;
}
