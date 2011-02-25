#include <stdio.h>

#define SQUARE(X)    X*X

int
main (int   argc,
      char *argv[])
{
  int num = 20;

  /* 정상 결과 출력 */
  printf ("Square of num : %d \n", SQUARE (num));
  printf ("Square of  -5 : %d \n", SQUARE (-5));
  printf ("Square of 2.5 : %g \n", SQUARE (2.5));

  /* 비정상 결과 출력 */
  printf ("Square of 3+2 : %d \n", SQUARE (3 + 2));

  return 0;
}
