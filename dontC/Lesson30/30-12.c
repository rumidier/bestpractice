#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  char *str1 = "이동춘은 나무꾼입니다. 오늘 아침에도 나무를 합니다.";
  char *str2 = "이동춘은 나무꾼입니다. " /* 세미콜론 없음에 주의 */
               "오늘 아침에도 나무를 합니다.";

  puts (str1);
  puts (str2);

  return 0;
}
