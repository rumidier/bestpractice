#include <stdio.h>
// #defind ADD  1
#define MIN   0

int
main (int   argc,
      char *argv[])
{
  int num1;
  int num2;

  printf ("두개의 정수 입력 : ");
  scanf ("%d %d", &num1, &num2);

#ifdef ADD
  printf ("%d + %d = %d \n", num1, num2, num1 + num2);
#endif

#ifdef MIN
  printf ("%d - %d = %d \n", num1, num2, num1 - num2);
#endif

  return 0;
}
