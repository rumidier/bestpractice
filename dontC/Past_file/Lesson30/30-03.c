#include <stdio.h>

#define PI    3.14
#define PROUDCT(X, Y)   ((X) * (Y))
#define CIRCLE_AREA(R)  (PROUDCT((R), (R)) *PI)

int
main (int   argc,
      char *argv[])
{
  double rad = 2.1;
  printf ("반지름 %g인 원의 넓이 : %g \n", rad, CIRCLE_AREA (rad));

  return 0;
}
