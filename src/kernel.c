#include "include/screen.h"
#include "include/colors.h"

// Entrypoint
int kmain() {
  changeColor(C_LIGHTBLUE,C_WHITE);
  cls();
  putStr("Doors v0.1.3!");
  return 0;   // Return Success Exit Code
}
