#include "include/screen.h"
#include "include/colors.h"

/** kmain
 *  Entrypoint of the program
 *
 *  @return Exit code
 */
int kmain() {
  initScreen(LIGHTBLUE,WHITE);

  uint8 index, head = 0x28, tail = 0xFD;

  for(index = 0x00; index < head; index++)
    putStr(" free ");
  putStr("\n\n\n\t\t\t\t  Doors v0.1.4!\n\n\n");
  for(index = 0x00; index < tail; index++)
    putStr(" free ");

  while(1);
  return 0;
}
