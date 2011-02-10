#include <stdio.h>

int main(void)
{
  int n;
  printf("0이상의 정수 입력 :");
  scanf("%d", &n);

  switch(n/10)               
    {  
    case 0:
      printf("0이상 10 미만 \n");
      break;
    case 1:
      printf("10이상 20 미만 \n");
      break;
    case 2:
      printf("20이상 30 미만 \n");
      break;
    default:
      printf("30이상 \n");
    }
  return 0;
}
