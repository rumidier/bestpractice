#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

typedef struct __point
{
  double xpos;
  double ypos;
} point;

typedef struct __circle
{
  point * cntptr;
  double rad;
} circle;

void
show_circle_info (const circle *ptr)
{
  printf ("원의 중심 : [%g, %g] \n",
          (ptr -> cntptr) -> xpos, (ptr -> cntptr) -> ypos);
  printf ("원의 넓이 : %g \n",
          (ptr -> rad) * (ptr -> rad) *PI);
}

int
main (int   argc,
      char *argv[])
{

  circle cl = {NULL, 2.5};
  cl.cntptr = (point *) malloc (sizeof (point ));

  cl.cntptr -> xpos = 1.1;
  cl.cntptr -> ypos = 2.2;

  show_circle_info (&cl);
  free (cl.cntptr);

  return 0;
}
