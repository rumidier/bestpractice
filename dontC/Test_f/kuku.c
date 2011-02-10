#include <stdio.h>

static void
gugu(int a, int b)
{
      int c,d,f;
  printf ("%d %d\n", a, b);
  if (a > b)
    {
  printf ("%d %d\n", a, b);
      for ( c = a; c<=b; c++ )
        {
          for ( d = 1; d<10; d++ )
            {
              f = c*d;
              printf("%d x %d = %d \n", c, d, f);
            }
        }
    }
  else
    {
      for( c = b; c>=a; c-- )
        {
          for ( d = 1; d<10; d++ )
            {
              f = c*d;
              printf("%d x %d = %d \n", c, d, f);
            }
        }
    }
}

int main(void)
{
  int a,b;
  printf("두 가지 숫자를 입력하세요. 그 사이에 포함된 구구단까지 모두 알려드립니다 : \n첫번째 숫자 입력\n : ");
  scanf("%d", &a);
  printf("두번째 숫자 입력 : ");
  scanf("%d", &b);
  gugu(a,b);
  return 0;
}
