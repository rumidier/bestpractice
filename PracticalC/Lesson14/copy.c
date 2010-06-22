#include <stdio.h>
#include <stdlib.h>

const char FILE_NAME [] = "input.txt";

int
main (int argc, char *argv[])
{
  int count = 0;
  FILE *in_file;
  int ch;

  in_file = fopen (FILE_NAME, "r");
  if (in_file == NULL) {
    printf ("Cannot open %s\n", FILE_NAME);
    exit 8;
  }

  while (1) {
    ch = fgetc (in_file);
    if (ch == EOF)
      break;
    ++count;
  }

  printf ("Number of charaters in %s is %d\n",
          FILE_NAME, count);

  fclose (in_file);

  return 0;
}
