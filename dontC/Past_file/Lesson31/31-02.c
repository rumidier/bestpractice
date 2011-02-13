#include <stdio.h>

struct point
{
  double xpos;
  double ypos;
};

int
main (void)
{
  /* 변수의 선언 */
  double num;
  struct point pnt;

  /* 변수의 초기화 */
  num = 1.2;
  pnt.xpos = 2.2;
  pnt.ypos = 3.4;

  /* 초기화된 값의 출력 */
  printf ("num : %g \n", num);
  printf ("pnt.xpos : %g \n", pnt.xpos);
  printf ("pnt.ypos : %g \n\n", pnt.ypos);

  /* 변수의 크기 계산 */
  printf ("num의 크기 : %d바이트 \n", sizeof (num));
  printf ("pnt의 크기 : %d바이트 \n", sizeof (pnt));

  return 0;
}
