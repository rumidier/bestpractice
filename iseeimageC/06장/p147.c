#include <stdio.h>

int
main (int argc, char *argv[])
{
  int a, b = 7;
  char s[40];
  printf ("이름을 입력해 주세요.\n");
  scanf ("%s", s);

  printf ("숫자 맞히기 퀴즈! 0부터 9사이의 숫자를 입력하세요.\n");

  while (a != b) {
    scanf ("%d", &a);

    if ((a == b - 1) || (a == b + 1))
      printf ("아깝네요!\n");
    else if (a > b + 1)
      printf ("좀 더 작은 수 입니다. \n");
    else if (a < b - 1)
      printf ("좀 더 큰 수 입니다.\n");
  }

  printf ("정답입니다. %s님, 축하합니다.\n", s);

  return 0;
}
