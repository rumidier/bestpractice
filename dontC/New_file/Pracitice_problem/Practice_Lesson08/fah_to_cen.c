/******************************************************************************************************
 * 섭씨 온도(C)와 화씨 온도(F)의 관계는 다음 식과 같다.
 * C = 5/9(F - 32)
 * 이 식을 참조하여 화씨 온도를 섭씨 온도로 변환하는 함수를 다음과 같은 형태로 정의하자.
 * double fahtocen (double fah) {...} //변환된 섭시 온도 변환
 * 그리고 화씨 124.5도를 섭시로 변환 하여 출력 하는 main함수로 정의 하자.물론 main 함수에서는 fahtocen 함
 * 수를 활용해야 한다.
 ******************************************************************************************************/

#include <stdio.h>

static double
fah_to_cen (double fah);

static double
fah_to_cen (double fah)
{
  double return_value;
  return_value = (5.0 / 9.0) * (fah - 32.0);

  return return_value;
}

int
main (int   argc,
      char *argv[])
{
  double fah;
  double cen;

  fah = 124.5;
  cen = fah_to_cen (fah);

  printf ("화씨(F)가 %6.2f 일때 섭씨(C)는%6.2f 입니다.\n", fah, cen);

  return 0;
}
