/***************************************************************************
 * inch 단위의 데이터를 cm 단위의 데이터로 변환하는 함수와 cm 단위의 데이터를
 * inch 단위의 데이터로 변환 하는 함수를 각각 다음의 형태로 정의 하자. 참고로
 * 1 inch 는 2.54cm 이다.
 * 그리고 3.24 inch를 cm 단위로 변환하여 그 결과를 출력하고, 12.7cm를 inch
 * 단위로 변환하여 그 결과를 출력하면 main 함수를 정의하자.
 **************************************************************************/
#include <stdio.h>

static double
convert_inch_to_cm (double inch);

static double
convert_cm_to_inch(double cm);

static double
convert_inch_to_cm (double inch)
{
  double inch_to_cm;

  inch_to_cm = inch * 2.54;

  return inch_to_cm;
}

static double
convert_cm_to_inch (double cm)
{
  double cm_to_inch;

  cm_to_inch = cm / 2.54;

  return cm_to_inch;
}

int
main (int   argc,
      char *argv[])
{
  double inch;
  double cm;
  double conv_inch;
  double conv_cm;

  inch = 3.24;
  cm = 12.7;

  conv_cm = convert_inch_to_cm (inch);
  conv_inch = convert_cm_to_inch (cm);

  printf ("%6.2finch 는 %6.2f cm\n", inch, conv_cm);
  printf ("%6.2fcm 은%6.2f inch\n", cm, conv_inch);

  return 0;
}
