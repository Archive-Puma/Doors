#include "lib/types.h"

// Entrypoint
int kmain() {
  char* framebuffer=(char*)0x000B8000;  // Framebuffer (size: 25x80)

  framebuffer[0] = 'K';                 // Print a letter
  framebuffer[1] = 0x04;                // Put a color

  return 0;                             // Return Success Exit Code
}
