// Entrypoint
int kmain() {
  char* vidmem=(char*)0xb8000;  // Video Memory Address
  vidmem[0] = 'K';              // Print a letter
  vidmem[1] = 0x04;             // Put a color

  return 0;                     // Return Success Exit Code
}
