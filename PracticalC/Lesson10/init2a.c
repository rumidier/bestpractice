#include <stdio.h>

int
main (int argc, char *argv[])
{
  int data [10];
  int twice [10];

  int index;

  for (index = 0; index < 10; ++index) {
    data [index] = index;
    twice [index] = index * 2;
  }

  return 0;
}
