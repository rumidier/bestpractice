#include <stdio.h>

#define FIRST_PART  7
#define LAST_PART   5
#define ALL_PARTS   (FIRST_PART + LAST_PART)

int
main (int argc, char *argv[])
{
  printf ("The square of all the parts is %d\n",
          ALL_PARTS * ALL_PARTS);

  return 0;
}
