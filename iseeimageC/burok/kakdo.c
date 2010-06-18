#include <stdio.h>
#include <math.h>
#define PI 3.14159

int
main (int argc, char *argv[])
{
  int kakdo = 30;
  double a, b, c;

  a = sin (kakdo * PI / 180);
  b = cos (kakdo * PI / 180);
  c = tan (kakdo * PI / 180);

  printf ("각도 %d \nsin %f\ncos %f\ntan %f\n",
          kakdo, a, b, c);

  return 0;
}
