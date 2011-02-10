#include <stdio.h>

struct __point
{
  double xpos;
  double ypos;
};

typedef struct __point point;

point increpos (point pnt)
{
  pnt.xpos++;
  pnt.ypos++;

  return pnt;
}

int
main (int   argc,
      char *argv[])
{
  point p1, p2, p3;
  p1.xpos = 0.5;
  p2.ypos = 1.5;

  p2 = p1;
  p3 = increpos (p2);

  printf ("X : %g \n", p3.xpos);
  printf ("Y : %g \n", p3.ypos);

  return 0;
}
