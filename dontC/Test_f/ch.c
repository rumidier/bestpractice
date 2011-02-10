#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char x;
  printf ("정수 입력 : \n");

  scanf ("%c", &x);
  printf ("아스키 출력 : %d \n",x );

  return 0;
}
