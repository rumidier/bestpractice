#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char c;
  int num;

  c = getchar ();
  num = getchar ();

  printf ("문자 : %c \n", c);
  printf ("정수 : %d \n", num);

  return 0;
}
