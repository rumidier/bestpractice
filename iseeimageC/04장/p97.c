#include <stdio.h>

int
main ()
{
  char x = 4, y;
  char *p = &x;

  y = *p;
  printf ("변수 x의 값은 %d입니다.\n", y);

  return 0;
}
