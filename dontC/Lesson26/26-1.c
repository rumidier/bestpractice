#include <stdio.h>

void showdata (const int *p);

int
main (int   argc,
      char *argv[])
{
  int num1 = 10;
  int num2 = 20;
  const int *ptr = &num1;

  //(*ptr)++;
  num1++;
  showdata (&num1);

  ptr = &num2;
  showdata (ptr);

  return 0;
}

void showdata (const int *p)
{
  /*
   * 이 안에서는 *p가 가리키는
   * 변수의 값을 바꿀수 없다.
   */
  printf ("%d \n", *p);
}
