/*********************************************************************************************
 * 인자로 전달된 정수에 해당하는 년도가 윤년 (2월을 29일로 둔해) 인지 아닌지를 확인하여 윤년
 * 인경우 에는 1을, 윤년이 아닌 경우에는 0을 출력하는 함수를 정의하자. 그리고 이 함수의 인자
 * 로 2000, 2012, 2015를 전달하여 출력결과를 확인 하는 main함수를 정의 하자. 참고로 윤년이 되기
 * 위한 조건은 다음과 같다
 * * 4로 나누어 떨어지는 년도는 윤년이다.
 * * 4로 나누어 떨어지지만 100으로도 나누어 떨어지는 년도는 윤년이 아니다.
 * * 4와 100으로 떨어지면서 400으로도 나누어 떨어지면 윤년이다.
 *********************************************************************************************/

#include <stdio.h>

static void
yun_print (int num);

static int 
yun_check (int year);


int
main (int   argc,
      char *argv[])
{
  int yun;

  
  printf ("2000년은 "); 
  yun = yun_check (2000);
  yun_print (yun);

  printf ("2012년은 ");
  yun = yun_check (2012);
  yun_print (yun);

  printf ("2015년은 ");
  yun = yun_check (2015);
  yun_print (yun);

  return 0;
}

static void
yun_print (int num)
{
  if (num)
    printf ("윤년 입니다.\n");
  else
    printf ("윤년이 아닙니다.\n");
}

static int
yun_check (int year)
{
  int yun_value;

  if (!(year % 4) && (year % 100))
    {
      if (!(year % 400))
        {
          yun_value = 1;
        }

      yun_value = 0;
    }
  else
    {
      yun_value = 1;
    }

  return yun_value;
}
