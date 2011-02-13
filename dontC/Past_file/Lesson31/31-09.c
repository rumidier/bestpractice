#include <stdio.h>

#define PI    3.14

typedef struct __point
{
  double xpos;
  double ypos;
} point;

typedef struct __circle
{
  point center;
  double rad;
} circle;

void
show_circle_info (const circle *ptr)
{
  printf ("원의 중심 : [%g, %g] \n",
          (ptr -> center).xpos, (ptr -> center).ypos);
  printf ("원의 넓이 : %g \n",
          (ptr -> rad) * (ptr -> rad) *PI);
}

int
main (int   argc,
      char *argv[])
{
  circle cl = {
      {1.1, 2.2},
      2.5
  };

  show_circle_info (&cl);
  return 0;
}
