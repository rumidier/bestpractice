#include <stdio.h>

struct point
{
  double xpos;
  double ypos;
};

typedef struct point point;
typedef struct point POINT;

int
main (int   argc,
      char *argv[])
{

  point p1;
  POINT p2;

  p1.xpos = 0.1, p1.ypos = 0.2;
  p2.xpos = 2.4, p2.ypos = 2.5;

  printf ("X축 거리 : %g \n", p2.xpos - p1.xpos);
  printf ("Y축 거리 : %g \n", p2.ypos - p1.ypos);

  return 0;
}
