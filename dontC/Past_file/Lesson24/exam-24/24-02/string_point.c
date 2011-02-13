#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int i;
  char *sptrarr[3] = {"AAA", "BBB", "CCC"};

  char **str_arr = sptrarr;

  int k = 0;
  while (k != 3)
    {
      for (i = 0; i < 3; i++)
        {
          printf ("%c", str_arr[k][i]);
        }
      printf ("\n");
      k++;
    }

  return 0;
}
