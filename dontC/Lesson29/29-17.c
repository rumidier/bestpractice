#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num1;
  float num2;
  char str[20];

  sscanf ("Hi! 24 3.15", "%s %d %g", str, &num1, &num2);
  printf ("문자열 추출 데이터 : %s %d %g \n\n", str, num1, num2);

  printf ("문자열 입력 : ");
  scanf ("%s %d %g", str, &num1, &num2);
  printf ("키보드 추출 데이터 : %s %d %g \n", str, num1, num2);

  return 0;
}
