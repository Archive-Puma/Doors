#include "string.h"

/** len
 *  Calculate the lenght of a string
 *
 *  @return  Lenght of the string
 */
uint8 len(string str) {
  uint8 length = 0;
  while(str[++length] != 0);
  return length;
}
