#include <stdio.h>

int
main (int argc, char *argv[])
{
  int a = 90;

  if (a > 80)
    {
      if (a == 100)
        printf ("만점입니다.\n");
      else
        printf ("조금만 더 노력하세요.\n");
    }
  else
    printf ("힘내세요!\n");

  return 0;
}
