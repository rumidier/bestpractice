#include <stdio.h>

int main(void)
{
  int num;
  int intLen, i;

  intLen=sizeof(int)*8; // int의 비트 수 계산
  printf ("int len %d\n", intLen);

  printf("정수 입력: ");
  scanf("%d", &num);

  printf ("입력된 수의 비트 열: ");
  for (i = 0; i < intLen; i++)
    {
      if (i != 0 && i % 8 == 0)
        printf(" ");
      printf("[%d]", num >> ((intLen - 1) - i) & 1);
    }
  printf("\n");

  return 0;
}
