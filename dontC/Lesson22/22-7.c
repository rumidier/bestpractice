#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int *p1 = 10;
  double *p2 = 0;

  printf ("쓰레기 값 1 : %p \n", p1);
  printf ("쓰레기 값 2 : %p \n", p2);

  printf ("어떤 정수가 찍힐가? %d \n", *p1);
  printf ("어떤 실수가 찍힐가? %f \n", *p2);

  *p1 = 25;
  *p2 = 3.15;

  printf ("저장된 정수 %d \n", *p1);
  printf ("저장된 실수 %f \n", *p2);

  return 0;
}
