#include <stdio.h>

struct _point2d {
  double x;
  double y;
} pt;

int
main (int argc, char *argv[])
{
  pt.x = 30.0;
  pt.y = 23.6;
  printf ("pt = (%4.1f, %4.1f)\n", pt.x, pt.y);

  return 0;
}
