#include <stdio.h>

#include "facttail.h"

int
main (int   argc,
      char *argv[])
{
  int a = 1;
  int n = 4;
  int value;

  value = facttail (n, a);

  printf ("value [%d]\n", value);

  return 0;
}
