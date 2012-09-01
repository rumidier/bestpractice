#include <stdio.h>
#include <string.h>

int
main (int argc, char *argv[])
{
  FILE *in, *out;

  int ch;
  char name[20];

  int count = 0;

  if (argc < 2)
    printf ("Sorry, i need the filename for argument\n");

  else {
    if ((in = fopen (argv[1], "r")) != NULL) {
      strcpy (name, argv[1]);
      strcat (name, ".out");
      out = fopen (name, "w");

      while ((ch = getc (in)) != EOF)
        if (count++ % 3 == 0)
          putc (ch, out);
      fclose (in);
      fclose (out);
    }
    else
      printf ("I can't find the file %s \n", argv[1]);
  }
  return 0;
}
