#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void usage() {
  printf("USAGE: cc256 (integer)\n\n");
  printf("  \033[1mcc256\033[0m will output a table representing up to 256 colors\n");
  printf("  which might be supported by your terminal emulator.\n");
  printf("  If a number is provided as the first argument, that'll define\n");
  printf("  the number of columns used. The default is 8.\n\n");
  printf("  rxvt-unicode supports 88 colors out of the box.\n");
  printf("  It'll support 256 colors if patched.\n");
  printf("  xterm supports 256 colors out of the box\n");
  exit(0);
}

int main(int argc, char *argv[]) {
  char *end = "\033[0m";
  int i;
  long int square_size;

  if(argv[1]) {
    int want_help;
    char *p;
    /* compare by 3 chars so --h will be valid
     * --help provided for context
     */
    want_help = strncmp(argv[1], "--help", 3);
    if(want_help == 0) {
      usage();
    }

    square_size = strtol(argv[1], &p, 10);
    if(square_size == 0) {
      square_size = 16;
    }
  }
  else {
    square_size = 8;
  }

  for(i=0;i<255;++i) {
    if(i % square_size == 0) {
      end = "\033[0m\n";
    }
    else {
      end = "\033[0m";
    }
    if(i == 0) {
      continue;
    }
    printf("\033[48;5;%d%s %03d %s", i, "m",i, end);
  }
  printf("\n");
  return(0);
}
