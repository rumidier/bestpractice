#include <stdio.h>

int
main (int argc, char *argv[])
{
  char a;

  printf ("1 - 3 중에서 좋아하는 숫자를 입력하세요.\n");

  a = getchar ();

  switch (a)
    {
    case '1' :
      printf ("오늘의 운세는 좋은 편입니다.\n");
      break;

    case '2' :
      printf ("오늘은 운수대통이군요.\n");
      break;
    case '3' :
      printf ("오늘의 운세는 보통입니다.\n");
      break;
    default :
      printf ("잘못 입력하셨습니다.\n");
    }

  return 0;
}
