#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
#line 1   "30-17.c"
  int dividend, divisor;

  printf ("두 개의 정수 입력 : ");
  scanf ("%d %d", &dividend, &divisor);

  if (divisor == 0)
    {
      puts ("실행 오류 발생");
      printf ("Line : main 함수의 %d행 \n", __LINE__);
      printf ("File : %s  \n", __FILE__);
    }
  else
    {
      printf ("나눗셈 결과 : %d \n", dividend / divisor);
    }
  
  return 0;
}
