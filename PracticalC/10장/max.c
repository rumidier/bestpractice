#include <stdio.h>

#define MAX 10

int
main (int argc, char *argv[])
{
  int counter;

  for (counter = MAX; counter > 0; --counter) {
    printf ("Hi there\n");
  }

  return 0;
}
