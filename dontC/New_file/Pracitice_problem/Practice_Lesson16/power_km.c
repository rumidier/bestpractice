#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  double km_h;
  double km;
  double liter;
  double power_km;
  double power_km_h;
  double temp;

  temp = 0;
  power_km = 0;
  power_km_h = 0;

  while (1)
    {
      printf ("속도(km/h), 이동거리(km), 오일 사용량(liter) 입력 : ");
      scanf ("%lf",&km_h);

      if (km_h == -1)
        break;

      scanf ("%lf %lf", &km, &liter);
      temp = km / liter;

      if (temp > power_km)
        {
          power_km = temp;
          power_km_h = km_h;
        }
    }

  printf ("최고의 연비는 %gkm/h에서 나옵니다.\n", power_km_h);

  return 0;
}
