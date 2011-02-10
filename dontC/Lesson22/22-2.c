#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int num1 = 3;
  char num2 = 'A';
  double num3 = 3.15;

  int *ptr1 = &num1;
  char *ptr2 = &num2;
  double *ptr3 = &num3;

  printf ("num1의 저장 위치 : %p\n", ptr1);
  printf ("num2의 저장 위치 : %p\n", ptr2);
  printf ("num3의 저장 위치 : %p\n", ptr3);

  printf ("포인터 변수 ptr1의 크기 : %d\n", sizeof (ptr1));
  printf ("포인터 변수 ptr2의 크기 : %d\n", sizeof (ptr2));
  printf ("포인터 변수 ptr3의 크기 : %d\n", sizeof (ptr3));

  return 0;
}
