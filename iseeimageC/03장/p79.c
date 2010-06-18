#include <stdio.h>

int
main (int argc, char *argv[])
{
  int x, y;
  char c;

  for (x = 2; x < 8; x++)
    printf ("16: 10:c | ");
  printf ("\n");

  for (x = 2; x < 8; x++)
    printf ("--------+-");
  printf ("\n");

  for (y = 0; y < 16; y++)
    {
      for (x = 2; x < 8; x++)
        {
          c = x * 16 + y;
          printf ("%2X:%3d:%c | ", c, c, c);
        }
      printf ("\n");
    }

  return 0;
}
