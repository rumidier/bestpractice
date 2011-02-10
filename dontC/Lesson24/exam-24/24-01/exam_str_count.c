#include <stdio.h>

int iscapital (char ch);

int
main (int   argc,
      char *argv[])
{
  char *str = "He Is My Best Friend!";
  int capcnt = 0;

  while (*str != '\0')
    {
      if (iscapital (*str))
        capcnt++;

      str++;
    }
  printf ("대문자 개수 : %d \n", capcnt);

  return 0;
}

int iscapital (char ch)
{
  if ('A' <= ch && ch <= 'Z')
    return 1;
  else
    return 0;
}
