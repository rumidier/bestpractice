#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int dividend, divisor;
  printf ("두 개의 정수 입력 : ");
  scanf ("%d %d", &dividend, &divisor);

  if (divisor == 0)
    {
      puts ("실행오류 발생");
      printf ("Line : %d \n", __LINE__);
      printf ("File : %s \n", __FILE__);
    }
  else
    {
      printf ("나눗셈 결과 : %d\n", dividend / divisor);
    }

  return 0;
}
