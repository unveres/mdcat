#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *in = NULL;

int main(int argc, char **argv)
{
  int ch, i;

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

  while ((ch = fgetc(in)) != EOF)
    putchar(ch);

  return 0;
}
