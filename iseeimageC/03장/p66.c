#include <stdio.h>

int
main (int argc, char *argv[])
{
  int a = 5;

  if (a % 2 == 0)
    printf ("%d는 우수입니다. \n", a);
  else
    printf ("%d는 기수 입니다.\n", a);

  return 0;
}
