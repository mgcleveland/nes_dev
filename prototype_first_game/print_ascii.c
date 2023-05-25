/* COMPILE with: cl65 --target nes -o sup.nes print_ascii.c */

#include "conio.h"
#include "unistd.h"

#define MSG_LENGTH 8


unsigned int calculate_position(const unsigned int i, const unsigned int offset)
{
  if (offset == 0) {
    return i;
  } else if (i < MSG_LENGTH) {
    return i;
  } else {
    return i - MSG_LENGTH;
  }
}

void print_msg()//const unsigned int offset)
{
  unsigned int i;
  char msg[MSG_LENGTH];

  msg[0] = 72;
  msg[1] = 73;
  msg[2] = 32;
  msg[3] = 82;
  msg[4] = 121;
  msg[5] = 97;
  msg[6] = 110;
  msg[7] = 33;

  for (i = 0; i < MSG_LENGTH; ++i) {
    // unsigned int position = calculate_position(i, offset);
    unsigned int position = i;
    cprintf("%c", (char)msg[position]);
  }
}


void reset_screen()
{
  unsigned char screen_width;
  unsigned char screen_height;
  unsigned char y;
  unsigned char x;
  //unsigned int new_x;

  screensize(&screen_width, &screen_height);

  y = wherey();
  x = wherex();
  cprintf("%i", (int)x);
  cputc(32);
  cprintf("%i", (int)y);
  cputc(32);
  cprintf("%i", (int)screen_width);
  cputc(32);
  //cprintf("%i", (int)screen_height);
  cputs(&(const char)screen_height);

  gotoy(y+1);

  if ((unsigned int)x + 1 + MSG_LENGTH >= screen_width) {
    clrscr();
    gotox(0);
  }
}


void main()
{
  /* unsigned int offset; */
  /* offset = 0; */

  for(;;) {
    print_msg();//offset);

    /* if (offset == MSG_LENGTH) { */
    /*   offset = 0; */
    /* } else { */
    /*   ++offset; */
    /* } */

    sleep(2);
    reset_screen();
  }
}
