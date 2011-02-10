#include <stdio.h>

typedef struct __point
{
  double xpos;
  double ypos;
} point;

int
main (int   argc,
      char *argv[])
{
  point pnt = {1.1, 2.2};

  printf ("구조체 pnt의 주소 : %p \n", &pnt);
  printf ("구조체 pnt의 첫 번째 멤버의 주소 : %p \n", &(pnt.xpos));

  return 0;
}
