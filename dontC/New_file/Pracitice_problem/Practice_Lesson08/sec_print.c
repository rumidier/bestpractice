/************************************************************************************************
 * 초 정보를 시:분:초의 정보로 변환하여 출력하는 함수를 다음과 같은 형태로 정의하자.
 * void sec_to_HMS (int  sec) {...} // 함수 내에서 시:분:초 정보출력
 * 그리고 이 함수를 활용해서 3245초와 5109초를 시:분:초의 정보로 변환하여 출력하는 main함수도 정의
 * 하자
 * ***********************************************************************************************/
#include <stdio.h>

static void
sec_to_hms (int sec);

static void
sec_to_hms (int sec)
{
  int hour;
  int min;
  int temp;

  hour = sec / 3600;
  temp = sec % 3600; 

  min = temp / 60;
  temp %= 60; 

  printf ("%d시 : %d분 : %d초 \n", hour, min, temp);
}

int
main (int   argc,
      char *argv[])
{

  printf ("3245초는 : \n");
  sec_to_hms (3245);
  printf ("5109초는 : \n");
  sec_to_hms (5109);

  return 0;
}
