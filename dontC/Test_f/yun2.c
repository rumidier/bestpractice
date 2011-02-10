#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
  int year;

  year = 2000;

  if ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
    printf ("%d 는 윤년 입니다.\n", year);
  else
    printf ("%d 는 윤년이 아닙니다.\n", year);

  year = 2012;

  if ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
    printf ("%d 는 윤년 입니다.\n", year);
  else
    printf ("%d 는 윤년이 아닙니다.\n", year);

  year = 2015;

  if ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
    printf ("%d 는 윤년 입니다.\n", year);
  else
    printf ("%d 는 윤년이 아닙니다.\n", year);
  return 0;
}
