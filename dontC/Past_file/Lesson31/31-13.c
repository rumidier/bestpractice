#include <stdio.h>

typedef struct box1
{
  int AAA;
  short BBB;
  short CCC;
} box1;

typedef struct box2
{
  short BBB;
  int AAA;
  short CCC;
} box2;

int
main (int   argc,
      char *argv[])
{
  box1 bx1;
  box2 bx2;

  printf ("구조체 box1의 변수 크기 : %d \n", sizeof (bx1));
  printf ("구조체 box2의 변수 크기 : %d \n", sizeof (bx2));

  return 0;
}
