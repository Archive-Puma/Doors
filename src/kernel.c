#include "include/screen.h"
#include "include/colors.h"

/** kmain
 *  Entrypoint of the program
 *
 *  @return Exit code
 */
int kmain() {
  initScreen(LIGHTBLUE,WHITE);
  putStr("\n\t\t\t\tDoors v0.1.4!\n\n");
  for(short i = 0; i < 1000; i++) {
    putStr(" free ");
  }
  return 0;
}
