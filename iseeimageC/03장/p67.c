#include <stdio.h>

int
main (int argc, char *argv[])
{
  int s = 65;

  printf ("당신의 점수는 %d점입니다.\n", s);

  if (s < 70)
    {
      printf ("평균까지 앞으로 %d점\n", 70 - s);
      printf ("힘내세요!\n");
    }
  else
    {
      printf ("잘 하셨습니다! \n");
    }

  return 0;
}
