#include <stdio.h>

double celtofah(void);
double fahtocel(void);

int main(void)
{
  double result, result1;

  result = celtofah();
  result1 = fahtocel();

  printf ("%f\n", result);
  printf ("%f\n", result1);

  return 0;
}

double celtofah (void)
{
  double c;
  printf("섭씨 온도 입력 :");
  scanf("%lf", &c);

  return 1.8*c+32;
}

double fahtocel(void)
{

  double f;
  printf("화씨 온도 입력 : ");
  scanf("%lf", &f);

  return (f/1.8)-32;
}
