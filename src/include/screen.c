#include "screen.h"

const string screen = (string) 0x000B8000;

// -------------------------------------------------------

/** initScreen
 *  Set the initial values of the screen
 *
 *  @param bg The background color
 *  @param fg The foreground color
 */
void initScreen(uint8 bg, uint8 fg) {
  pointer.x = 0x00;
  pointer.y = 0x00;
  changeColor(bg, fg);
  cls();
}

// -------------------------------------------------------

/** checkPointer
 *  Write a new line when the position of the
 *  cursor reaches the width of the screen
 */
void checkPointer() {
  if(pointer.x >= WIDTH)
    nl();
}

/** moveCursor
 *  Moves the cursor of the framebuffer to the given position
 *    0x3D4 - Framebuffer Command Port
 *    0x3D5 - Framebuffer Data Port
 *    0x0E  - Framebuffer High Byte Command
 *    0x0F  - Framebuffer Low Byte Command
 *
 *  @param position The new position of the cursor
 *//*
void moveCursor(uint16 position) {
  outport(0x3D4, 0x0E);
  outport(0x3D5, (position >> 8) & 0x00FF);
  outport(0x3D4, 0x0F);
  outport(0x3D5, position & 0x00FF);
}
*/

// -------------------------------------------------------

/** putCh
 *  Write a char in stdout
 *
 *  @param ch Char to write
 */
void putCh(uint8 ch) {
  uint8 space;
  uint16 position;

  switch(ch) {
    case '\n':
      nl();
      break;
    case '\t':
      for(space = 0; space < TAB_SIZE; space++)
        putCh(' ');
      break;
    default:
      position = (pointer.x + pointer.y * WIDTH) * OFFSET;
      screen[position] = ch;
      screen[position+1] = pointer.c;
      pointer.x++;
      break;
  }

  checkPointer();
}

/** putStr
 *  Write a string in stdout
 *
 *  @param str Text to write
 */
void putStr(string str) {
  write(str, len(str));
}

/** write
 *  Write a string in stdout
 *
 *  @param buffer Text to write
 *  @param len    Lenght of the buffer
 */
void write(string buffer, uint32 len) {
  uint32 index;
  for(index = 0; index < len; index++)
    putCh(buffer[index]);
}

// -------------------------------------------------------

/** nl
 *  Write a new line
 */
void nl() {
  pointer.y++;
  pointer.x = 0x00;
}

/** cls
 *  Clean the screen
 */
void cls() {
  uint8 line;
  for(line = 0; line < HEIGHT; line++)
    clsLine(line);
}

/** clsLine
 *  Clean the given line
 *
 *  @param line  Height of the line to clean
 */
void clsLine(uint8 line) {
  uint16 position;
  uint16 origin = line * WIDTH * OFFSET;
  for(position = origin; position < origin + WIDTH * OFFSET; position++) {
    screen[position++] = ' ';
    screen[position] = pointer.c;
  }
}

// -------------------------------------------------------

/** changeColor
 *  Set the color of the background and the foreground
 *
 *  @param bg The background color
 *  @param fg The foreground color
 */
void changeColor(uint8 bg, uint8 fg) {
  pointer.c = ((bg & 0x0F) << 4) + (fg & 0x0F);
}
