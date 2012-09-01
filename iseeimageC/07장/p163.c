#include <stdio.h>

struct _colorpoint2d {
  double x, y;
  int colorid;
} cpt;

struct _colorpoint2d *ppt = &cpt;

int
main (int argc, char *argv[])
{
  ppt -> x = 2.4;
  ppt -> y = 3.2;
  ppt -> colorid = 1;
  printf (" (%3.1f, %3.1f) color = %d\n",
          ppt -> x, ppt -> y, ppt -> colorid);

  return 0;
}
