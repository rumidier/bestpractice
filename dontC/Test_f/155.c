#include <stdio.h>
int main(void)
{
  int dan=3, num=1, n;

  printf("숫자를 입력하시오...");
  scanf("%d", &n);

  while(num<n+1)
    {
      printf ("n [%d]\n", n);
      printf("%d*%d=%d \n", dan, num, dan*num);
      num++;
    }
  return 0;
}
