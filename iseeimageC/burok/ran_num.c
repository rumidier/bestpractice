#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

int
main (int argc, char *argv[])
{
  int n = -1;
  int answer;

  srand (time (NULL));

  answer = (rand() % MAX_NUM) + 1;

  printf ("수 맞히기 퀴즈! 1~%d 까지의 수를 입력하세요.\n", MAX_NUM);

  while (n != answer) {
    scanf ("%d", &n);

    if (n == answer - 1 || n == answer + 1)
      printf ("아깝습니다!\n");
    else if (n > answer + 1)
      printf ("좀 더 작은 수를 넣으세요.\n");
    else if (n < answer - 1)
      printf ("좀 더 큰 수를 넣으세요.\n");
  }

  printf ("정답입니다!!\n");

  return 0;
}
