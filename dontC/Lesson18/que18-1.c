#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char str1[] = "ORANGE";
  char str2[] = "BANANA";
  char test;
  int i;

  for (i = 0; i < 6; i++)
    {

      test = str1[i];
      str1[i] = str2[i];
      str2[i] = test;
    }
    printf ("str1[%s] \n", str1);
    printf ("str2[%s] \n", str2);

  return 0;
}
