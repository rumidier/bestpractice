#include <stdio.h>

#include "fact.h"

int
main (int   argc,
      char *argv[])
{
  int a = 4;
  int value;

  value = fact (a);

  printf ("value [%d]\n", value);

  return 0;
}
