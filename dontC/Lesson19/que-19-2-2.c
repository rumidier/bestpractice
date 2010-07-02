#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char str[4][30];
  int i;

  for (i = 0; i < 4; i++)
    {
        {
          printf ("입력해주세여 : "); scanf ("%s", str[i]);
        }
    }

  for (i = 0; i < 4; i++)
    {
      printf ("%s\n", str[3 - i]);
    }

  return 0;
}
