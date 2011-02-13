#include <stdio.h>

void callbyval (int   num)
{
  num++;
}

void callbyref (int   *ptr)
{
  (*ptr)++;
}

int
main (int   argc,
      char *argv[])
{
  int val = 10;
  callbyval (val);
  printf ("callbyval : %d \n", val);

  callbyref (&val);
  printf ("callbyref : %d \n", val);

  return 0;
}
