#include <stdio.h>

static double
juk_dan (double money, int year);

static double
juk_bok (double money, int year);

int
main (int   argc,
      char *argv[])
{
  double money;
  int year;

  double bokri;
  double danri;

  printf ("얼마를 예치 하십니까? : ");
  scanf ("%lf", &money);
  printf ("몇년간 하십니까? : ");
  scanf ("%d", &year);
/*
  if (year < 5)
    {
      while (1)
        {
          printf ("\n최소 5년 이상 예치 하셔야 합니다.\n");
          printf ("몇년간 하십니까? : ");
          scanf ("%d", &year);

          if (year < 5)
            continue;
          break;
        }
    }
    */
  bokri = juk_bok (money, year);
  danri = juk_dan (money, year);

  printf ("단리 이자율 %g\n", danri);
  printf ("복리 이자율 %g\n", bokri);

  return 0;
}

static double
juk_dan (double money, int year)
{
  double dan;
  dan = money * 0.072;

  return (money + (dan * year));
}

static double
juk_bok (double money, int year)
{
  int i;
  double bokri;
  double return_bokri;

  i = 0;
  bokri = 0;
  return_bokri = money;

  while (i < year)
    {
      printf ("[%lf]\n", return_bokri);
      bokri = return_bokri * 0.047;
      printf ("%lf\n", bokri);
      return_bokri += bokri;
      printf (">>[%lf]\n", return_bokri);
      i++;
    }

 return return_bokri; 
}
