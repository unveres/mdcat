#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *in = NULL;

int main(int argc, char **argv)
{
  int    ch,
         i;
  size_t in_col,
         in_row;

  enum {
    TEXT, TRIM
  } mode;

  (void)mode;

  if (in == NULL)
    in = stdin; 

  if (argc > 1) {
    for (i = 1; i < argc; ++i) {
      if (strcmp(argv[i], "-") == 0) {
        in = stdin;
        main(0, NULL);
      }
      else {
        if ((in = fopen(argv[i], "r")) == NULL) {
          perror("fopen");
          exit(1);
        }

        main(0, NULL);
        fclose(in);
      }
    }

    return 0;
  }

  in_col = 1;
  in_row = 1;

  while ((ch = fgetc(in)) != EOF) {
    if (ch == '\n') {
      in_col = 1;
      ++in_row;
    }

    /* here it will be a lot of things to do */
    /* putchar(ch); */

    ++in_col;
  }

  return 0;
}
