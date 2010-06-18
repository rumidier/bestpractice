#include <stdio.h>

int
main (int argc, char *argv[])
{
  char a;
  short b;

  printf ("a의 어드레스는 %p b의 어드레스는 %p\n", &a, &b);

  return 0;
}
