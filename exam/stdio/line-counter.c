#include <stdio.h>

int
main (int argc, char *argv[])
{
  char line [100];
  int line_num = 1;

  while (1)
    {
      fgets (line, sizeof (line), stdin);

      if (feof (stdin))
        {
          break;
        }

      printf ("%6d  %s", line_num, line);
      line_num++;
    }

  return 0;
}
