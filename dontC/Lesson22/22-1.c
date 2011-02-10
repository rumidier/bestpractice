#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num1 = 3;
  char num2 = 'A';
  double num3 = 3.15;

  printf ("num1의 저장 위치 : %p \n", &num1);
  printf ("num2의 저장 위치 : %p \n", &num2);
  printf ("num3의 저장 위치 : %p \n", &num3);

  printf ("num1의 주소 값 크기 : %d \n", sizeof (&num1));
  printf ("num2의 주소 값 크기 : %d \n", sizeof (&num2));
  printf ("num3의 주소 값 크기 : %d \n", sizeof (&num3));

  return 0;
}
